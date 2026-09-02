/*-----------------------------------------------------------------------------
 * Umicom AI Creator Module
 * File: include/umicom/ai_creator/readiness.h
 *
 * PURPOSE:
 *   Expose Framework-owned readiness and ownership evidence through the thin product boundary.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/

#ifndef UMICOM_AI_CREATOR_READINESS_H
#define UMICOM_AI_CREATOR_READINESS_H

#include "umicom/application/runtime/readiness.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Provide the ai creator readiness report operation used by this module and its client
 * applications.
 */
UmiStatus umi_ai_creator_readiness_report(
    UmiApplicationReadinessReport *out_report);
/**
 * Provide the ai creator readiness next feature operation used by this module and its
 * client applications.
 */
const UmiExperienceFeatureDefinition *umi_ai_creator_readiness_next_feature(void);

#ifdef __cplusplus
}
#endif

#endif
