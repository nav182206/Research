/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_8185
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1b435b10324fe9937f254bb00718f78d5e50837a
 */

void qemu_bh_delete(QEMUBH *bh)

{

    qemu_bh_cancel(bh);

    qemu_free(bh);

}
