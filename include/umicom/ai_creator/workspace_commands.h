/*-----------------------------------------------------------------------------
 * Umicom AI Creator Module
 * File: include/umicom/ai_creator/workspace_commands.h
 *
 * PURPOSE:
 *   Expose product-facing layout, panel and context commands implemented by the Framework runtime.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/

#ifndef UMICOM_AI_CREATOR_WORKSPACE_COMMANDS_H
#define UMICOM_AI_CREATOR_WORKSPACE_COMMANDS_H

#include "umicom/application/runtime/context_review.h"
#include "umicom/ai_creator/runtime.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Provide the ai creator workspace select layout operation used by this module and its
 * client applications.
 */
UmiStatus umi_ai_creator_workspace_select_layout(
    UmiApplicationWorkspaceRuntime *runtime,
    const char *layout_id);
/**
 * Provide the ai creator workspace activate panel operation used by this module and its
 * client applications.
 */
UmiStatus umi_ai_creator_workspace_activate_panel(
    UmiApplicationWorkspaceRuntime *runtime,
    const char *panel_id);
/**
 * Provide the ai creator workspace set context operation used by this module and its
 * client applications.
 */
UmiStatus umi_ai_creator_workspace_set_context(
    UmiApplicationWorkspaceRuntime *runtime,
    const char *group_id,
    const char *value);
/**
 * Provide the ai creator workspace commands operation used by this module and its client
 * applications.
 */
const UmiApplicationCommandSurface *umi_ai_creator_workspace_commands(
    const UmiApplicationWorkspaceRuntime *runtime);

/* Review several linked groups without changing this product's runtime.
 * Framework owns validation, copied review rows and atomic UI publication.
 * The runtime must borrow this product's canonical experience. Use the shared
 * review summary/row functions to display the proposal, then explicitly apply.
 * Destroy the review after use; context values never authorise commands. */
UmiStatus umi_ai_creator_workspace_context_review(
    UmiApplicationWorkspaceRuntime *runtime,
    const UmiApplicationContextChange *changes, size_t count,
    UmiApplicationContextReview **out_review);
UmiStatus umi_ai_creator_workspace_context_apply(
    UmiApplicationWorkspaceRuntime *runtime, UmiApplicationContextReview *review);
/* Remove a linked group through the same Framework transaction. */
UmiStatus umi_ai_creator_workspace_clear_context(
    UmiApplicationWorkspaceRuntime *runtime, const char *group_id);

#ifdef __cplusplus
}
#endif

#endif
