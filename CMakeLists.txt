#-----------------------------------------------------------------------------
# Umicom AI Creator Module
# File: CMakeLists.txt
#
# PURPOSE:
#   Build a thin C23 product composition over Framework-owned application
#   experience, runtime and workbench contracts.
#
# Created by: Sammy Hegab
# Organisation: Umicom Foundation
# Licence: MIT
#-----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.24)

project(
    AiCreatorModule
    VERSION 0.1.0
    DESCRIPTION "Thin Umicom AI Creator composition over Umicom Framework"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

option(UMICOM_AI_CREATOR_BUILD_CONSOLE
       "Build the native Umicom AI Creator verification console"
       ON)

include(CTest)
include(GNUInstallDirs)

if(NOT TARGET Umicom::Framework)
    find_package(UmicomFramework CONFIG REQUIRED)
endif()

if(NOT TARGET Umicom::application)
    message(FATAL_ERROR
        "Umicom AI Creator requires Framework target Umicom::application")
endif()

if(NOT COMMAND umicom_apply_warnings)
    function(umicom_apply_warnings target)
        if(MSVC)
            target_compile_options(${target} PRIVATE /W4)
        else()
            target_compile_options(${target} PRIVATE
                -Wall -Wextra -Wpedantic -Wconversion -Wshadow)
        endif()
    endfunction()
endif()

if(NOT COMMAND umicom_apply_sanitizers)
    function(umicom_apply_sanitizers target)
    endfunction()
endif()

add_library(umicom_ai_creator_module STATIC
    src/application.c
    src/workspace.c
)
add_library(Umicom::ai_creator_module ALIAS umicom_ai_creator_module)

target_include_directories(umicom_ai_creator_module PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries(umicom_ai_creator_module PUBLIC
    Umicom::Framework
    Umicom::application
)
umicom_apply_warnings(umicom_ai_creator_module)
umicom_apply_sanitizers(umicom_ai_creator_module)

if(UMICOM_AI_CREATOR_BUILD_CONSOLE)
    add_executable(umicom-ai-creator-console
        src/console/main.c)
    target_link_libraries(umicom-ai-creator-console PRIVATE Umicom::ai_creator_module)
    umicom_apply_warnings(umicom-ai-creator-console)
    umicom_apply_sanitizers(umicom-ai-creator-console)
endif()

if(BUILD_TESTING)
    add_executable(creator-application-test
        tests/test_application.c)
    target_link_libraries(creator-application-test PRIVATE Umicom::ai_creator_module)
    umicom_apply_warnings(creator-application-test)
    umicom_apply_sanitizers(creator-application-test)
    add_test(NAME creator.module.application
             COMMAND creator-application-test)

    add_executable(creator-workspace-test
        tests/test_workspace.c)
    target_link_libraries(creator-workspace-test PRIVATE Umicom::ai_creator_module)
    umicom_apply_warnings(creator-workspace-test)
    umicom_apply_sanitizers(creator-workspace-test)
    add_test(NAME creator.module.workspace
             COMMAND creator-workspace-test)
endif()

install(TARGETS umicom_ai_creator_module
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
if(TARGET umicom-ai-creator-console)
    install(TARGETS umicom-ai-creator-console
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()
install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES application.umicom.yaml
    DESTINATION ${CMAKE_INSTALL_DATADIR}/umicom/applications/creator)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
    install(FILES LICENSE
        DESTINATION ${CMAKE_INSTALL_DATADIR}/licenses/creator)
endif()

message(STATUS "Umicom AI Creator Module version: ${PROJECT_VERSION}")
message(STATUS "Umicom AI Creator uses Framework-owned application experience")
