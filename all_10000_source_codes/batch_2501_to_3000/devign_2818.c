/* 
 * Benchmark Sample ID : devign_2818
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2b38b277a7882a592f4f2ec955084b2b756daaa
 */

aio_ctx_dispatch(GSource     *source,

                 GSourceFunc  callback,

                 gpointer     user_data)

{

    AioContext *ctx = (AioContext *) source;



    assert(callback == NULL);

    aio_dispatch(ctx, true);

    return true;

}
