/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6566
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static void test_in_coroutine(void)

{

    Coroutine *coroutine;



    g_assert(!qemu_in_coroutine());



    coroutine = qemu_coroutine_create(verify_in_coroutine);

    qemu_coroutine_enter(coroutine, NULL);

}
