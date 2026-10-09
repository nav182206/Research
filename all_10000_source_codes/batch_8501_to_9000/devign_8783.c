/* 
 * Benchmark Sample ID : devign_8783
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4e59b545868a5ee5f59b346337f0c44209929334
 */

QEMUBH *qemu_bh_new(QEMUBHFunc *cb, void *opaque)

{

    QEMUBH *bh;



    bh = qemu_malloc(sizeof(*bh));

    bh->cb = cb;

    bh->opaque = opaque;



    return bh;

}
