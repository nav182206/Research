/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2673
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ac531cb6e542b1e61d668604adf9dc5306a948c0
 */

START_TEST(qdict_get_try_int_test)

{

    int ret;

    const int value = 100;

    const char *key = "int";



    qdict_put(tests_dict, key, qint_from_int(value));



    ret = qdict_get_try_int(tests_dict, key, 0);

    fail_unless(ret == value);

}
