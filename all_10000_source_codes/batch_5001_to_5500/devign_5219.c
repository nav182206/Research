/* 
 * Benchmark Sample ID : devign_5219
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2c8f86961b6eaac705be21bc98299f5517eb0b6b
 */

static void test_ide_mbr(bool use_device, MBRcontents mbr)

{

    char *argv[256];

    int argc;

    Backend i;

    const char *dev;



    argc = setup_common(argv, ARRAY_SIZE(argv));

    for (i = 0; i < backend_last; i++) {

        cur_ide[i] = &hd_chst[i][mbr];

        dev = use_device ? (is_hd(cur_ide[i]) ? "ide-hd" : "ide-cd") : NULL;

        argc = setup_ide(argc, argv, ARRAY_SIZE(argv), i, dev, i, mbr, "");

    }

    qtest_start(g_strjoinv(" ", argv));

    test_cmos();

    qtest_end();

}
