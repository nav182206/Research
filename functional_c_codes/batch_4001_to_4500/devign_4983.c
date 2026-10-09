/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4983
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b6fcf32d9b851a83dedcb609091236b97cc4a985
 */

static void test_validate_fail_struct_nested(TestInputVisitorData *data,

                                              const void *unused)

{

    UserDefNested *udp = NULL;

    Error *err = NULL;

    Visitor *v;



    v = validate_test_init(data, "{ 'string0': 'string0', 'dict1': { 'string1': 'string1', 'dict2': { 'userdef1': { 'integer': 42, 'string': 'string', 'extra': [42, 23, {'foo':'bar'}] }, 'string2': 'string2'}}}");



    visit_type_UserDefNested(v, &udp, NULL, &err);

    g_assert(err);

    qapi_free_UserDefNested(udp);

}
