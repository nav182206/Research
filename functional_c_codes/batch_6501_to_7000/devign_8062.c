/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8062
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=17b74b98676aee5bc470b173b1e528d2fce2cf18
 */

void qjson_finish(QJSON *json)

{

    json_end_object(json);

}
