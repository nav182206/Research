/* 
 * Benchmark Sample ID : devign_6024
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=25c4d9cc845fb58f624dae8c0f690e20c70e7a1d
 */

static int op_to_mov(int op)

{

    switch (op_bits(op)) {

    case 32:

        return INDEX_op_mov_i32;

#if TCG_TARGET_REG_BITS == 64

    case 64:

        return INDEX_op_mov_i64;

#endif

    default:

        fprintf(stderr, "op_to_mov: unexpected return value of "

                "function op_bits.\n");

        tcg_abort();

    }

}
