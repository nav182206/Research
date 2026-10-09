/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5685
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b125f9dc7bd68cd4c57189db4da83b0620b28a72
 */

static TranslationBlock *tb_alloc(target_ulong pc)

{

    TranslationBlock *tb;



    if (tcg_ctx.tb_ctx.nb_tbs >= tcg_ctx.code_gen_max_blocks ||

        (tcg_ctx.code_gen_ptr - tcg_ctx.code_gen_buffer) >=

         tcg_ctx.code_gen_buffer_max_size) {

        return NULL;

    }

    tb = &tcg_ctx.tb_ctx.tbs[tcg_ctx.tb_ctx.nb_tbs++];

    tb->pc = pc;

    tb->cflags = 0;

    return tb;

}
