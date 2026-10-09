/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3356
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6e0d8677cb443e7408c0b7a25a93c6596d7fa380
 */

static int gen_jz_ecx_string(DisasContext *s, target_ulong next_eip)

{

    int l1, l2;



    l1 = gen_new_label();

    l2 = gen_new_label();

    gen_op_jnz_ecx[s->aflag](l1);

    gen_set_label(l2);

    gen_jmp_tb(s, next_eip, 1);

    gen_set_label(l1);

    return l2;

}
