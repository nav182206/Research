/* 
 * Benchmark Sample ID : devign_5658
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ac531cb6e542b1e61d668604adf9dc5306a948c0
 */

START_TEST(qobject_to_qdict_test)

{

    fail_unless(qobject_to_qdict(QOBJECT(tests_dict)) == tests_dict);

}
