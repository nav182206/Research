/* 
 * Benchmark Sample ID : devign_1619
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3db211f3c80bb996a704d665fe275619f728bd4
 */

static void test_validate_qmp_introspect(TestInputVisitorData *data,

                                           const void *unused)

{

    do_test_validate_qmp_introspect(data, test_qmp_schema_json);

    do_test_validate_qmp_introspect(data, qmp_schema_json);

}
