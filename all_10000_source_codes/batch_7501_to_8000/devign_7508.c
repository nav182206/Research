/* 
 * Benchmark Sample ID : devign_7508
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6e0d8677cb443e7408c0b7a25a93c6596d7fa380
 */

void OPPROTO op_addw_EDI_T0(void)

{

    EDI = (EDI & ~0xffff) | ((EDI + T0) & 0xffff);

}
