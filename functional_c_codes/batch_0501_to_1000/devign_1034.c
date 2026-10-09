/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1034
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9154b02c53bb6685797c973fcdbec51c4714777d
 */

void vring_teardown(Vring *vring)

{

    hostmem_finalize(&vring->hostmem);

}
