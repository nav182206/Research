/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7824
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6e0d8677cb443e7408c0b7a25a93c6596d7fa380
 */

static inline void gen_lods(DisasContext *s, int ot)

{

    gen_string_movl_A0_ESI(s);

    gen_op_ld_T0_A0(ot + s->mem_index);

    gen_op_mov_reg_T0(ot, R_EAX);

    gen_op_movl_T0_Dshift[ot]();

#ifdef TARGET_X86_64

    if (s->aflag == 2) {

        gen_op_addq_ESI_T0();

    } else

#endif

    if (s->aflag) {

        gen_op_addl_ESI_T0();

    } else {

        gen_op_addw_ESI_T0();

    }

}
