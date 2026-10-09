/* 
 * Benchmark Sample ID : devign_2417
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b106ad9185f35fc4ad669555ad0e79e276083bd7
 */

int64_t qcow2_alloc_clusters(BlockDriverState *bs, int64_t size)

{

    int64_t offset;

    int ret;



    BLKDBG_EVENT(bs->file, BLKDBG_CLUSTER_ALLOC);

    offset = alloc_clusters_noref(bs, size);

    if (offset < 0) {

        return offset;

    }



    ret = update_refcount(bs, offset, size, 1, QCOW2_DISCARD_NEVER);

    if (ret < 0) {

        return ret;

    }



    return offset;

}
