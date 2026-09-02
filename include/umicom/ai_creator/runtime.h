/*-----------------------------------------------------------------------------
 * Umicom AI Creator Module
 * File: include/umicom/ai_creator/runtime.h
 *
 * PURPOSE:
 *   Bind the thin product to the Framework-owned application workspace runtime without duplicating services.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/

#ifndef UMICOM_AI_CREATOR_RUNTIME_H
#define UMICOM_AI_CREATOR_RUNTIME_H

#include "umicom/application/runtime/runtime.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Initialise ai creator runtime from caller-provided values so later operations receive a
 * known state.
 */
UmiStatus umi_ai_creator_runtime_init(
    UmiApplicationWorkspaceRuntime *out_runtime);
/**
 * Provide the ai creator runtime health operation used by this module and its client
 * applications.
 */
UmiStatus umi_ai_creator_runtime_health(
    UmiApplicationCapabilityProbe probe,
    void *user_data,
    UmiApplicationRuntimeHealth *out_health);
/**
 * Provide the ai creator runtime experience operation used by this module and its client
 * applications.
 */
const UmiApplicationExperienceDefinition *umi_ai_creator_runtime_experience(void);

#ifdef __cplusplus
}
#endif

#endif
