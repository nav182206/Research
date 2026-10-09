/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2351
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2ad645d2854746b55ddfd1d8e951f689cca5d78f
 */

static void test_nop(gconstpointer data)

{

    QTestState *s;

    const char *machine = data;

    char *args;



    args = g_strdup_printf("-display none -machine %s", machine);

    s = qtest_start(args);

    if (s) {

        qtest_quit(s);

    }

    g_free(args);

}
