/* 
 * Benchmark Sample ID : devign_6025
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e7ca56562990991bc614a43b9351ee0737f3045d
 */

void object_property_get_uint16List(Object *obj, const char *name,

                                    uint16List **list, Error **errp)

{

    Error *err = NULL;

    StringOutputVisitor *ov;

    Visitor *v;

    char *str;



    ov = string_output_visitor_new(false);

    object_property_get(obj, string_output_get_visitor(ov),

                        name, &err);

    if (err) {

        error_propagate(errp, err);

        goto out;

    }

    str = string_output_get_string(ov);

    v = string_input_visitor_new(str);

    visit_type_uint16List(v, NULL, list, errp);



    g_free(str);

    visit_free(v);

out:

    string_output_visitor_cleanup(ov);

}
