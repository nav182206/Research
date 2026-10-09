/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4236
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f090c9d4ad5812fb92843d6470a1111c15190c4c
 */

OP(zerof64)

{

    set_opf64(PARAM1, 0);

    FORCE_RET();

}
