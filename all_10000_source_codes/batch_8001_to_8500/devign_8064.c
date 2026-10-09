/* 
 * Benchmark Sample ID : devign_8064
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=acc4af3fec335bb0778456f72bfb2c3591c11da4
 */

Object *object_dynamic_cast(Object *obj, const char *typename)

{

    GSList *i;



    /* Check if typename is a direct ancestor */

    if (object_is_type(obj, typename)) {

        return obj;

    }



    /* Check if obj has an interface of typename */

    for (i = obj->interfaces; i; i = i->next) {

        Interface *iface = i->data;



        if (object_is_type(OBJECT(iface), typename)) {

            return OBJECT(iface);

        }

    }



    /* Check if obj is an interface and its containing object is a direct

     * ancestor of typename */

    if (object_is_type(obj, TYPE_INTERFACE)) {

        Interface *iface = INTERFACE(obj);



        if (object_is_type(iface->obj, typename)) {

            return iface->obj;

        }

    }



    return NULL;

}
