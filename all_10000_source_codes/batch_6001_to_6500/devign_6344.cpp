/* 
 * Benchmark Sample ID : devign_6344
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7372c2b926200db295412efbb53f93773b7f1754
 */

static inline void gen_store(DisasContext *s, int opsize, TCGv addr, TCGv val)

{

    int index = IS_USER(s);

    s->is_mem = 1;

    switch(opsize) {

    case OS_BYTE:

        tcg_gen_qemu_st8(val, addr, index);

        break;

    case OS_WORD:

        tcg_gen_qemu_st16(val, addr, index);

        break;

    case OS_LONG:

    case OS_SINGLE:

        tcg_gen_qemu_st32(val, addr, index);

        break;

    default:

        qemu_assert(0, "bad store size");

    }

    gen_throws_exception = gen_last_qop;

}
