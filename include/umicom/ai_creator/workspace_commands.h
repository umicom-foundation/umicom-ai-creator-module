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

#ifdef __cplusplus
}
#endif

#endif
