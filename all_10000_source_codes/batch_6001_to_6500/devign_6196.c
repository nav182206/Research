/* 
 * Benchmark Sample ID : devign_6196
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e1c8237df5395f6a453f18109bd9dd33fb2a397c
 */

static void property_get_str(Object *obj, Visitor *v, void *opaque,

                             const char *name, Error **errp)

{

    StringProperty *prop = opaque;

    char *value;



    value = prop->get(obj, errp);

    if (value) {

        visit_type_str(v, &value, name, errp);

        g_free(value);

    }

}
