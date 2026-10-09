/* 
 * Benchmark Sample ID : devign_1621
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6e0d8677cb443e7408c0b7a25a93c6596d7fa380
 */

void OPPROTO op_mov_T0_cc(void)

{

    T0 = cc_table[CC_OP].compute_all();

}
