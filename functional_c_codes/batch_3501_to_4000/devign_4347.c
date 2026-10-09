/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4347
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bd79255d2571a3c68820117caf94ea9afe1d527e
 */

static void spr_read_decr (DisasContext *ctx, int gprn, int sprn)

{

    if (use_icount) {

        gen_io_start();

    }

    gen_helper_load_decr(cpu_gpr[gprn], cpu_env);

    if (use_icount) {

        gen_io_end();

        gen_stop_exception(ctx);

    }

}
