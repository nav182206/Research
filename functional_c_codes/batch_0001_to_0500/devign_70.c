/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_70
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=976620ac4018db142d82cd42bb7774f40290ce7e
 */

void object_property_get_uint16List(Object *obj, const char *name,

                                    uint16List **list, Error **errp)

{

    StringOutputVisitor *ov;

    StringInputVisitor *iv;



    ov = string_output_visitor_new(false);

    object_property_get(obj, string_output_get_visitor(ov),

                        name, errp);

    iv = string_input_visitor_new(string_output_get_string(ov));

    visit_type_uint16List(string_input_get_visitor(iv),

                          list, NULL, errp);

    string_output_visitor_cleanup(ov);

    string_input_visitor_cleanup(iv);

}
