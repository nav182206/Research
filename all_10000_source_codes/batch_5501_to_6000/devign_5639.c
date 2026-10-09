/* 
 * Benchmark Sample ID : devign_5639
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3a53009fa044a554dbdeacf30a6b8ea3eb02fe63
 */

char *object_property_print(Object *obj, const char *name, bool human,

                            Error **errp)

{

    StringOutputVisitor *mo;

    char *string;



    mo = string_output_visitor_new(human);

    object_property_get(obj, string_output_get_visitor(mo), name, errp);

    string = string_output_get_string(mo);

    string_output_visitor_cleanup(mo);

    return string;

}
