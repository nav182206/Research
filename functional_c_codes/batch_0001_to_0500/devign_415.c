/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_415
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b8b8753e4d94901627b3e86431230f2319215c4
 */

static void test_nesting(void)

{

    Coroutine *root;

    NestData nd = {

        .n_enter  = 0,

        .n_return = 0,

        .max      = 128,

    };



    root = qemu_coroutine_create(nest);

    qemu_coroutine_enter(root, &nd);



    /* Must enter and return from max nesting level */

    g_assert_cmpint(nd.n_enter, ==, nd.max);

    g_assert_cmpint(nd.n_return, ==, nd.max);

}
