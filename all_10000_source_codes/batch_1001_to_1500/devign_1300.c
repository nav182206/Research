/* 
 * Benchmark Sample ID : devign_1300
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7372c2b926200db295412efbb53f93773b7f1754
 */

static inline TCGv gen_extend(TCGv val, int opsize, int sign)

{

    TCGv tmp;



    switch (opsize) {

    case OS_BYTE:

        tmp = tcg_temp_new();

        if (sign)

            tcg_gen_ext8s_i32(tmp, val);

        else

            tcg_gen_ext8u_i32(tmp, val);

        break;

    case OS_WORD:

        tmp = tcg_temp_new();

        if (sign)

            tcg_gen_ext16s_i32(tmp, val);

        else

            tcg_gen_ext16u_i32(tmp, val);

        break;

    case OS_LONG:

    case OS_SINGLE:

        tmp = val;

        break;

    default:

        qemu_assert(0, "Bad operand size");

    }

    return tmp;

}
