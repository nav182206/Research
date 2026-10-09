/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1957
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d9bce9d99f4656ae0b0127f7472db9067b8f84ab
 */

void do_store_xer (void)

{

    xer_so = (T0 >> XER_SO) & 0x01;

    xer_ov = (T0 >> XER_OV) & 0x01;

    xer_ca = (T0 >> XER_CA) & 0x01;

    xer_cmp = (T0 >> XER_CMP) & 0xFF;

    xer_bc = (T0 >> XER_BC) & 0x3F;

}
