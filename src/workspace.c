/*-----------------------------------------------------------------------------
 * Umicom AI Creator Module
 * File: src/workspace.c
 *
 * PURPOSE:
 *   Project canonical Framework layouts and next-feature planning through the thin application boundary.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/

#include "umicom/ai_creator/workspace.h"

#include "umicom/ai_creator/application.h"
#include "umicom/application/experience_plan.h"

/*
 * Return the number of records represented by ai creator workspace layout without changing
 * their state.
 */
size_t umi_ai_creator_workspace_layout_count(void)
{
    const UmiApplicationExperienceDefinition *definition =
        umi_ai_creator_application_experience();
    return definition != NULL ? definition->layout_count : 0U;
}

/*
 * Find ai creator workspace layout while leaving the underlying catalogue or model owned
 * by this module.
 */
const UmiExperienceLayoutDefinition *umi_ai_creator_workspace_layout_at(
    size_t index)
{
    const UmiApplicationExperienceDefinition *definition =
        umi_ai_creator_application_experience();
    return definition != NULL && index < definition->layout_count
        ? &definition->layouts[index] : NULL;
}

/*
 * Provide the ai creator workspace default operation used by this module and its client
 * applications.
 */
const UmiExperienceLayoutDefinition *umi_ai_creator_workspace_default(void)
{
    const UmiApplicationExperienceDefinition *definition =
        umi_ai_creator_application_experience();
    return definition != NULL
        ? umi_application_experience_layout_find(
            definition, definition->default_layout_id)
        : NULL;
}

/*
 * Provide the ai creator workspace next feature operation used by this module and its
 * client applications.
 */
const UmiExperienceFeatureDefinition *umi_ai_creator_workspace_next_feature(
    void)
{
    return umi_application_experience_next_feature(
        umi_ai_creator_application_experience());
}
