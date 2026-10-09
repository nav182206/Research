/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3529
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d4d34b0d3f5af5c8e09980da0de2eebe9a27dc71
 */

static void get_enum(Object *obj, Visitor *v, void *opaque,

                     const char *name, Error **errp)

{

    DeviceState *dev = DEVICE(obj);

    Property *prop = opaque;

    int *ptr = qdev_get_prop_ptr(dev, prop);



    visit_type_enum(v, ptr, prop->info->enum_table,

                    prop->info->name, prop->name, errp);

}
