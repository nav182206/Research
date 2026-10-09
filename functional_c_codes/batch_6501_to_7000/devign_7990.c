/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7990
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6e0d8677cb443e7408c0b7a25a93c6596d7fa380
 */

void OPPROTO op_addw_ESI_T0(void)

{

    ESI = (ESI & ~0xffff) | ((ESI + T0) & 0xffff);

}
