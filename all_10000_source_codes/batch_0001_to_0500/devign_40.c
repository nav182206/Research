/* 
 * Benchmark Sample ID : devign_40
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3db211f3c80bb996a704d665fe275619f728bd4
 */

static void test_validate_struct_nested(TestInputVisitorData *data,

                                         const void *unused)

{

    UserDefTwo *udp = NULL;

    Visitor *v;



    v = validate_test_init(data, "{ 'string0': 'string0', "

                           "'dict1': { 'string1': 'string1', "

                           "'dict2': { 'userdef': { 'integer': 42, "

                           "'string': 'string' }, 'string': 'string2'}}}");



    visit_type_UserDefTwo(v, NULL, &udp, &error_abort);

    qapi_free_UserDefTwo(udp);

}
