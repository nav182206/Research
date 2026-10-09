/* 
 * Benchmark Sample ID : devign_4775
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b7f43fe46029d8fd0594cd599fa2599dcce0f553
 */

Object *object_dynamic_cast(Object *obj, const char *typename)

{

    if (object_class_dynamic_cast(object_get_class(obj), typename)) {

        return obj;

    }



    return NULL;

}
