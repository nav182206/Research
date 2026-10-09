/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2246
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ac531cb6e542b1e61d668604adf9dc5306a948c0
 */

static void qdict_setup(void)

{

    tests_dict = qdict_new();

    fail_unless(tests_dict != NULL);

}
