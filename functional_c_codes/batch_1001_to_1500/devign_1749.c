/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1749
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4cae4d5acaea23f3def84c8dc67ef5106323e5cb
 */

int qdev_build_hotpluggable_device_list(Object *obj, void *opaque)

{

    GSList **list = opaque;

    DeviceState *dev = DEVICE(obj);



    if (dev->realized && object_property_get_bool(obj, "hotpluggable", NULL)) {

        *list = g_slist_append(*list, dev);

    }



    object_child_foreach(obj, qdev_build_hotpluggable_device_list, opaque);

    return 0;

}
