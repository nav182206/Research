/* 
 * Benchmark Sample ID : devign_9171
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a980f7f2c2f4d7e9a1eba4f804cd66dbd458b6d4
 */

static void qvirtio_9p_stop(void)

{

    qtest_end();

    rmdir(test_share);

    g_free(test_share);

}
