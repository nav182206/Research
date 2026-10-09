/* 
 * Benchmark Sample ID : devign_2734
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3db211f3c80bb996a704d665fe275619f728bd4
 */

static Visitor *validate_test_init_raw(TestInputVisitorData *data,

                                       const char *json_string)

{

    return validate_test_init_internal(data, json_string, NULL);

}
