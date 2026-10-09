/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3726
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4715d42efe8632b0f9d2594a80e917de45e4ef88
 */

static void property_get_bool(Object *obj, Visitor *v, void *opaque,

                              const char *name, Error **errp)

{

    BoolProperty *prop = opaque;

    bool value;



    value = prop->get(obj, errp);

    visit_type_bool(v, &value, name, errp);

}
