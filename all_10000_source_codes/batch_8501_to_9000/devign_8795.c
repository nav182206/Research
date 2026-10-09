/* 
 * Benchmark Sample ID : devign_8795
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=17b74b98676aee5bc470b173b1e528d2fce2cf18
 */

void json_end_object(QJSON *json)

{

    qstring_append(json->str, " }");

    json->omit_comma = false;

}
