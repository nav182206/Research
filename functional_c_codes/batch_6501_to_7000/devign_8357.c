/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8357
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2c8f86961b6eaac705be21bc98299f5517eb0b6b
 */

static void test_ide_none(void)

{

    char *argv[256];



    setup_common(argv, ARRAY_SIZE(argv));

    qtest_start(g_strjoinv(" ", argv));

    test_cmos();

    qtest_end();

}
