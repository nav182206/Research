/* 
 * Benchmark Sample ID : devign_2190
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4715d42efe8632b0f9d2594a80e917de45e4ef88
 */

int object_property_get_enum(Object *obj, const char *name,

                             const char *typename, Error **errp)

{

    StringOutputVisitor *sov;

    StringInputVisitor *siv;

    char *str;

    int ret;

    ObjectProperty *prop = object_property_find(obj, name, errp);

    EnumProperty *enumprop;



    if (prop == NULL) {

        return 0;

    }



    if (!g_str_equal(prop->type, typename)) {

        error_setg(errp, "Property %s on %s is not '%s' enum type",

                   name, object_class_get_name(

                       object_get_class(obj)), typename);

        return 0;

    }



    enumprop = prop->opaque;



    sov = string_output_visitor_new(false);

    object_property_get(obj, string_output_get_visitor(sov), name, errp);

    str = string_output_get_string(sov);

    siv = string_input_visitor_new(str);

    string_output_visitor_cleanup(sov);

    visit_type_enum(string_input_get_visitor(siv),

                    &ret, enumprop->strings, NULL, name, errp);



    g_free(str);

    string_input_visitor_cleanup(siv);



    return ret;

}
