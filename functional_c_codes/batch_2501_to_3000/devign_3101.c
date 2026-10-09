/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3101
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dcd042282d855edf70df90b7d61d33b515320b7a
 */

AioContext *bdrv_get_aio_context(BlockDriverState *bs)

{

    /* Currently BlockDriverState always uses the main loop AioContext */

    return qemu_get_aio_context();

}
