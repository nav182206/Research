/* 
 * Benchmark Sample ID : devign_4535
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=69e58af92cf90a1a0551c73880928afa6753fa5f
 */

void unregister_savevm(DeviceState *dev, const char *idstr, void *opaque)

{

    SaveStateEntry *se, *new_se;

    char id[256] = "";



    if (dev && dev->parent_bus && dev->parent_bus->info->get_dev_path) {

        char *path = dev->parent_bus->info->get_dev_path(dev);

        if (path) {

            pstrcpy(id, sizeof(id), path);

            pstrcat(id, sizeof(id), "/");

            qemu_free(path);



    pstrcat(id, sizeof(id), idstr);



    QTAILQ_FOREACH_SAFE(se, &savevm_handlers, entry, new_se) {

        if (strcmp(se->idstr, id) == 0 && se->opaque == opaque) {

            QTAILQ_REMOVE(&savevm_handlers, se, entry);




            qemu_free(se);
