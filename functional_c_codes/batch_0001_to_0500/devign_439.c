/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_439
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6b98bd649520d07df4d1b7a0a54ac73bf178519c
 */

static void raw_aio_unplug(BlockDriverState *bs)

{

#ifdef CONFIG_LINUX_AIO

    BDRVRawState *s = bs->opaque;

    if (s->use_aio) {

        laio_io_unplug(bs, s->aio_ctx, true);

    }

#endif

}
