/* 
 * Benchmark Sample ID : devign_3933
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=64607d088132abdb25bf30d93e97d0c8df7b364c
 */

void object_property_add_child(Object *obj, const char *name,

                               Object *child, Error **errp)

{

    Error *local_err = NULL;

    gchar *type;



    type = g_strdup_printf("child<%s>", object_get_typename(OBJECT(child)));



    object_property_add(obj, name, type, object_get_child_property, NULL,

                        object_finalize_child_property, child, &local_err);

    if (local_err) {

        error_propagate(errp, local_err);

        goto out;

    }

    object_ref(child);

    g_assert(child->parent == NULL);

    child->parent = obj;



out:

    g_free(type);

}
