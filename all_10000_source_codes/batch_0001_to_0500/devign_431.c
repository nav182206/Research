/* 
 * Benchmark Sample ID : devign_431
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=158f0545d81b2aca1c936490f80d13988616910e
 */

ASSStyle *ff_ass_style_get(ASSSplitContext *ctx, const char *style)

{

    ASS *ass = &ctx->ass;

    int i;



    if (!style || !*style)

        style = "Default";

    for (i=0; i<ass->styles_count; i++)

        if (!strcmp(ass->styles[i].name, style))

            return ass->styles + i;

    return NULL;

}
