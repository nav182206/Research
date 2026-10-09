/* 
 * Benchmark Sample ID : devign_3135
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ac531cb6e542b1e61d668604adf9dc5306a948c0
 */

START_TEST(qdict_get_str_test)

{

    const char *p;

    const char *key = "key";

    const char *str = "string";



    qdict_put(tests_dict, key, qstring_from_str(str));



    p = qdict_get_str(tests_dict, key);

    fail_unless(p != NULL);

    fail_unless(strcmp(p, str) == 0);

}
