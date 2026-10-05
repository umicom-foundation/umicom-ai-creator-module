# umicom-ai-creator-module
Thin C23 Umicom AI Creator application composition over Umicom Framework

## Review linked context values

AI Creator exposes Framework's reviewed context changes through
`umi_ai_creator_workspace_context_review`, `umi_ai_creator_workspace_context_apply`
and `umi_ai_creator_workspace_clear_context` in
`umicom/ai_creator/workspace_commands.h`. A context group is a named value that
related panels can share; for example, a host could use `creation.project` with the sample
value `sample-project`. The host must connect that name to its panel consumers.

1. Use a runtime initialised with this product's canonical experience. Prepare
   the requested changes with the review function; preparation changes no live state.
2. Display the copied Framework summary and rows. Keep the runtime and its
   workbench alive while the user reviews the proposed values. If the summary
   reports UI differences, show the captured UI value beside the cached value.
3. Apply only after acceptance, then destroy the review. If the workspace changed,
   prepare a fresh review. Cancelling only destroys the review.

This is a module API; native review screens are separate host work. Context edits
do not execute product commands or external operations. The shared guide at
`framework/docs/guides/REVIEWING_LINKED_CONTEXTS.html` in the Applications checkout
explains capacity, ownership, thread coordination and recovery in more detail.

[Import a document for local source retrieval](../../framework/docs/learning/import-searchable-documents.html) explains the shared UTF-8 file/text import, complete passage preview, atomic save and grounded-question workflow. Imports remain local until you separately approve a model request.

[Review changes to your source library](../../framework/docs/learning/review-source-library-changes.html) explains explicit passage selection, complete replacement/removal previews, atomic application and retained evidence for earlier answers. RAG, LLM and Creator share this native workspace page.
