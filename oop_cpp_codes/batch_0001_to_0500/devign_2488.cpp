/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2488
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ef1e1e0782e99c9dcf2b35e5310cdd8ca9211374
 */

void unregister_savevm(DeviceState *dev, const char *idstr, void *opaque)

{

    SaveStateEntry *se, *new_se;

    char id[256] = "";



    if (dev) {

        char *path = qdev_get_dev_path(dev);

        if (path) {

            pstrcpy(id, sizeof(id), path);

            pstrcat(id, sizeof(id), "/");

            g_free(path);

        }

    }

    pstrcat(id, sizeof(id), idstr);



    QTAILQ_FOREACH_SAFE(se, &savevm_state.handlers, entry, new_se) {

        if (strcmp(se->idstr, id) == 0 && se->opaque == opaque) {

            QTAILQ_REMOVE(&savevm_state.handlers, se, entry);

            if (se->compat) {

                g_free(se->compat);

            }

            g_free(se->ops);

            g_free(se);

        }

    }

}
