/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7416
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c2b38b277a7882a592f4f2ec955084b2b756daaa
 */

void aio_bh_call(QEMUBH *bh)

{

    bh->cb(bh->opaque);

}
