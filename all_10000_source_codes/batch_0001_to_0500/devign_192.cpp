/* 
 * Benchmark Sample ID : devign_192
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=38e0735eb76a1479917ef3501a208d4f70998494
 */

void register_device_unmigratable(DeviceState *dev, const char *idstr,

                                                            void *opaque)

{

    SaveStateEntry *se;

    char id[256] = "";



    if (dev && dev->parent_bus && dev->parent_bus->info->get_dev_path) {

        char *path = dev->parent_bus->info->get_dev_path(dev);

        if (path) {

            pstrcpy(id, sizeof(id), path);

            pstrcat(id, sizeof(id), "/");

            g_free(path);

        }

    }

    pstrcat(id, sizeof(id), idstr);



    QTAILQ_FOREACH(se, &savevm_handlers, entry) {

        if (strcmp(se->idstr, id) == 0 && se->opaque == opaque) {

            se->no_migrate = 1;

        }

    }

}
