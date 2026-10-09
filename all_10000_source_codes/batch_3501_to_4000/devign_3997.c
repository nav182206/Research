/* 
 * Benchmark Sample ID : devign_3997
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cf081fca4e3cc02a309659b571ab0c5b225ea4cf
 */

static void vmdk_refresh_limits(BlockDriverState *bs, Error **errp)

{

    BDRVVmdkState *s = bs->opaque;

    int i;



    for (i = 0; i < s->num_extents; i++) {

        if (!s->extents[i].flat) {

            bs->bl.write_zeroes_alignment =

                MAX(bs->bl.write_zeroes_alignment,

                    s->extents[i].cluster_sectors);

        }

    }

}
