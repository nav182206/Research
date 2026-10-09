/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_418
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c5a49c63fa26e8825ad101dfe86339ae4c216539
 */

static bool use_goto_tb(DisasContext *ctx, target_ulong dest)

{

    /* Suppress goto_tb in the case of single-steping and IO.  */

    if ((ctx->base.tb->cflags & CF_LAST_IO) || ctx->base.singlestep_enabled) {

        return false;

    }

    return true;

}
