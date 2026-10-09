/* 
 * Benchmark Sample ID : devign_5071
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5cd230819ec26caf199bf73d38cf2407344e4443
 */

static coroutine_fn int cloop_co_read(BlockDriverState *bs, int64_t sector_num,

                                      uint8_t *buf, int nb_sectors)

{

    int ret;

    BDRVCloopState *s = bs->opaque;

    qemu_co_mutex_lock(&s->lock);

    ret = cloop_read(bs, sector_num, buf, nb_sectors);

    qemu_co_mutex_unlock(&s->lock);

    return ret;

}
