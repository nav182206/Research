/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_483
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=17b74b98676aee5bc470b173b1e528d2fce2cf18
 */

static void json_emit_element(QJSON *json, const char *name)

{

    /* Check whether we need to print a , before an element */

    if (json->omit_comma) {

        json->omit_comma = false;

    } else {

        qstring_append(json->str, ", ");

    }



    if (name) {

        qstring_append(json->str, "\"");

        qstring_append(json->str, name);

        qstring_append(json->str, "\" : ");

    }

}
