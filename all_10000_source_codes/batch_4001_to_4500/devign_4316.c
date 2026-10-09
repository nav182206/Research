/* 
 * Benchmark Sample ID : devign_4316
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=003fad6e2cae5311d3aea996388c90e3ab17de90
 */

void qcow2_free_clusters(BlockDriverState *bs,

                          int64_t offset, int64_t size)

{

    int ret;



    BLKDBG_EVENT(bs->file, BLKDBG_CLUSTER_FREE);

    ret = update_refcount(bs, offset, size, -1);

    if (ret < 0) {

        fprintf(stderr, "qcow2_free_clusters failed: %s\n", strerror(-ret));

        abort();

    }

}
