/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3085
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6e0d8677cb443e7408c0b7a25a93c6596d7fa380
 */

static inline void gen_stack_update(DisasContext *s, int addend)

{

#ifdef TARGET_X86_64

    if (CODE64(s)) {

        gen_op_addq_ESP_im(addend);

    } else

#endif

    if (s->ss32) {

        gen_op_addl_ESP_im(addend);

    } else {

        gen_op_addw_ESP_im(addend);

    }

}
