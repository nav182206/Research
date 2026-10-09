/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3984
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0ed6dc1a982fd029557a17fda7606d679a6ebb28
 */

void error_set_field(Error *err, const char *field, const char *value)

{

    QDict *dict = qdict_get_qdict(err->obj, "data");

    return qdict_put(dict, field, qstring_from_str(value));

}
