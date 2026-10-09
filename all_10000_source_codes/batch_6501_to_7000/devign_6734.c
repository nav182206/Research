/* 
 * Benchmark Sample ID : devign_6734
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=60cbfb95522b33c3ec1dd4fa32da261c6c3d6a9d
 */

static void expr_error(const char *fmt)

{

    term_printf(fmt);

    term_printf("\n");

    longjmp(expr_env, 1);

}
