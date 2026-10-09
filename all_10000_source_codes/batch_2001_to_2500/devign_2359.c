/* 
 * Benchmark Sample ID : devign_2359
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3b098d56979d2f7fd707c5be85555d114353a28d
 */

char *object_property_print(Object *obj, const char *name, bool human,

                            Error **errp)

{

    StringOutputVisitor *sov;

    char *string = NULL;

    Error *local_err = NULL;



    sov = string_output_visitor_new(human);

    object_property_get(obj, string_output_get_visitor(sov), name, &local_err);

    if (local_err) {

        error_propagate(errp, local_err);

        goto out;

    }



    string = string_output_get_string(sov);



out:

    visit_free(string_output_get_visitor(sov));

    return string;

}
