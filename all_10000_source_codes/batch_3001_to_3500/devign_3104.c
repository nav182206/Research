/* 
 * Benchmark Sample ID : devign_3104
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cf7c0ff521b0710079aa28f21937fb7dbb3f5224
 */

static int nvdimm_plugged_device_list(Object *obj, void *opaque)

{

    GSList **list = opaque;



    if (object_dynamic_cast(obj, TYPE_NVDIMM)) {

        *list = g_slist_append(*list, DEVICE(obj));

    }



    object_child_foreach(obj, nvdimm_plugged_device_list, opaque);

    return 0;

}
