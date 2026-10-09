/* 
 * Benchmark Sample ID : devign_6070
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=024a6fbdb9d8cbc4d7f833b23db51c9d1004bc47
 */

void qdev_property_add_child(DeviceState *dev, const char *name,

                             DeviceState *child, Error **errp)

{

    gchar *type;



    type = g_strdup_printf("child<%s>", child->info->name);



    qdev_property_add(dev, name, type, qdev_get_child_property,

                      NULL, NULL, child, errp);



    qdev_ref(child);

    g_assert(child->parent == NULL);

    child->parent = dev;



    g_free(type);

}
