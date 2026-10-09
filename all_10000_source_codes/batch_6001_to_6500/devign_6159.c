/* 
 * Benchmark Sample ID : devign_6159
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2ee73ac3a855fb0cfba3db91fdd1ecebdbc6f971
 */

void OPPROTO op_fdiv_ST0_FT0(void)

{

    ST0 /= FT0;

}
