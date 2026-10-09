/* 
 * Benchmark Sample ID : devign_469
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c3e10c7b4377c1cbc0a4fbc12312c2cf41c0cda7
 */

static always_inline void gen_op_subfo (void)

{

    gen_op_move_T2_T0();

    gen_op_subf();

    gen_op_check_subfo();

}
