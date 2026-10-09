/* 
 * Benchmark Sample ID : devign_2812
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ac531cb6e542b1e61d668604adf9dc5306a948c0
 */

START_TEST(qdict_put_exists_test)

{

    int value;

    const char *key = "exists";



    qdict_put(tests_dict, key, qint_from_int(1));

    qdict_put(tests_dict, key, qint_from_int(2));



    value = qdict_get_int(tests_dict, key);

    fail_unless(value == 2);



    fail_unless(qdict_size(tests_dict) == 1);

}
