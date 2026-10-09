/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_533
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8de3458a07376b0a96772e586b6dba5e93432f52
 */

static NvencSurface *get_free_frame(NvencContext *ctx)

{

    int i;



    for (i = 0; i < ctx->nb_surfaces; i++) {

        if (!ctx->surfaces[i].lockCount) {

            ctx->surfaces[i].lockCount = 1;

            return &ctx->surfaces[i];

        }

    }



    return NULL;

}
