/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8519
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c3e10c7b4377c1cbc0a4fbc12312c2cf41c0cda7
 */

static always_inline void gen_op_subfeo (void)

{

    gen_op_move_T2_T0();

    gen_op_subfe();

    gen_op_check_subfo();

}
