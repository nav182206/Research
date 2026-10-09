/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7617
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1b0952445522af73b0e78420a9078b3653923703
 */

static void test_hbitmap_iter_past(TestHBitmapData *data,

                                    const void *unused)

{

    hbitmap_test_init(data, L3, 0);

    hbitmap_test_set(data, 0, L3);

    hbitmap_test_check(data, L3);

}
