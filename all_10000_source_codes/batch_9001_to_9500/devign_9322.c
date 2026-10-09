/* 
 * Benchmark Sample ID : devign_9322
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3edf1e73d568c646202e9faa6224df4fee1bd0e6
 */

static coroutine_fn int dmg_co_read(BlockDriverState *bs, int64_t sector_num,

                                    uint8_t *buf, int nb_sectors)

{

    int ret;

    BDRVDMGState *s = bs->opaque;

    qemu_co_mutex_lock(&s->lock);

    ret = dmg_read(bs, sector_num, buf, nb_sectors);

    qemu_co_mutex_unlock(&s->lock);

    return ret;

}
