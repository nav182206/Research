/* 
 * Benchmark Sample ID : devign_4217
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6b98bd649520d07df4d1b7a0a54ac73bf178519c
 */

void laio_io_plug(BlockDriverState *bs, void *aio_ctx)

{

    struct qemu_laio_state *s = aio_ctx;



    s->io_q.plugged++;

}
