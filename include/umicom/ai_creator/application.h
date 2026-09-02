/*-----------------------------------------------------------------------------
 * Umicom AI Creator Module
 * File: include/umicom/ai_creator/application.h
 *
 * PURPOSE:
 *   Expose the thin application composition over Framework-owned experience metadata and services.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/

#ifndef UMICOM_AI_CREATOR_APPLICATION_H
#define UMICOM_AI_CREATOR_APPLICATION_H

#include "umicom/application/experience.h"
#include "umicom/application/experience_status.h"

#ifdef __cplusplus
extern "C" {
#endif

#define UMI_AI_CREATOR_MODULE_API_VERSION 1U

/**
 * Provide the ai creator application id operation used by this module and its client
 * applications.
 */
const char *umi_ai_creator_application_id(void);

/**
 * Provide the ai creator application experience operation used by this module and its
 * client applications.
 */
const UmiApplicationExperienceDefinition *
umi_ai_creator_application_experience(void);

/**
 * Provide the ai creator application status operation used by this module and its client
 * applications.
 */
UmiStatus umi_ai_creator_application_status(
    UmiApplicationExperienceStatus *out_status);

#ifdef __cplusplus
}
#endif

#endif
