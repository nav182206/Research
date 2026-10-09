/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7925
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2e6fc7eb1a4af1b127df5f07b8bb28af891946fa
 */

static int raw_probe_blocksizes(BlockDriverState *bs, BlockSizes *bsz)

{

    BDRVRawState *s = bs->opaque;

    int ret;



    ret = bdrv_probe_blocksizes(bs->file->bs, bsz);

    if (ret < 0) {

        return ret;

    }



    if (!QEMU_IS_ALIGNED(s->offset, MAX(bsz->log, bsz->phys))) {

        return -ENOTSUP;

    }



    return 0;

}
