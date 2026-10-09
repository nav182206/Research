/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8913
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2f6f826e03e09eb3b65b3a764580d66b857e3a23
 */

MemdevList *qmp_query_memdev(Error **errp)

{

    Object *obj;

    MemdevList *list = NULL;



    obj = object_get_objects_root();

    if (obj == NULL) {

        return NULL;

    }



    if (object_child_foreach(obj, query_memdev, &list) != 0) {

        goto error;

    }



    return list;



error:

    qapi_free_MemdevList(list);

    return NULL;

}
