/* 
 * Benchmark Sample ID : devign_5739
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c2b6428d388b3f03261be7b0be770919e4e3e5ec
 */

void bdrv_set_aio_context(BlockDriverState *bs, AioContext *new_context)
{
    bdrv_drain(bs); /* ensure there are no in-flight requests */
    bdrv_detach_aio_context(bs);
    /* This function executes in the old AioContext so acquire the new one in
     * case it runs in a different thread.
     */
    aio_context_acquire(new_context);
    bdrv_attach_aio_context(bs, new_context);
    aio_context_release(new_context);
