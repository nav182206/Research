/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_300
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=05601ed2de60df0e344d6b783a6bc0c1ff2b5d1f
 */

void object_property_set_qobject(Object *obj, QObject *value,

                                 const char *name, Error **errp)

{

    Visitor *v;

    /* TODO: Should we reject, rather than ignore, excess input? */

    v = qobject_input_visitor_new(value, false);

    object_property_set(obj, v, name, errp);

    visit_free(v);

}
