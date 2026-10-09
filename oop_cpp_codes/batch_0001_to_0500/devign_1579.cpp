/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_1579
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c3481247e58ff3f13337ce0a262b058799bd156c
 */

void object_add(const char *type, const char *id, const QDict *qdict,

                Visitor *v, Error **errp)

{

    Object *obj;

    const QDictEntry *e;

    Error *local_err = NULL;



    if (!object_class_by_name(type)) {

        error_setg(errp, "invalid class name");

        return;

    }



    obj = object_new(type);

    if (qdict) {

        for (e = qdict_first(qdict); e; e = qdict_next(qdict, e)) {

            object_property_set(obj, v, e->key, &local_err);

            if (local_err) {

                goto out;

            }

        }

    }



    if (!object_dynamic_cast(obj, TYPE_USER_CREATABLE)) {

        error_setg(&local_err, "object type '%s' isn't supported by object-add",

                   type);

        goto out;

    }



    user_creatable_complete(obj, &local_err);

    if (local_err) {

        goto out;

    }



    object_property_add_child(container_get(object_get_root(), "/objects"),

                              id, obj, &local_err);

out:

    if (local_err) {

        error_propagate(errp, local_err);

    }

    object_unref(obj);

}
