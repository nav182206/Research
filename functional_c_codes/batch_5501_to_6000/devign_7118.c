/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7118
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cf081fca4e3cc02a309659b571ab0c5b225ea4cf
 */

static void bdrv_qed_refresh_limits(BlockDriverState *bs, Error **errp)

{

    BDRVQEDState *s = bs->opaque;



    bs->bl.write_zeroes_alignment = s->header.cluster_size >> BDRV_SECTOR_BITS;

}
