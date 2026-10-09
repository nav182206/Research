/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7052
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3db211f3c80bb996a704d665fe275619f728bd4
 */

Visitor *validate_test_init(TestInputVisitorData *data,

                             const char *json_string, ...)

{

    Visitor *v;

    va_list ap;



    va_start(ap, json_string);

    v = validate_test_init_internal(data, json_string, &ap);

    va_end(ap);

    return v;

}
