/* 
 * Benchmark Sample ID : devign_8032
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a5cf8262e4eb9c4646434e2c6211ef8608db3233
 */

static char *idebus_get_fw_dev_path(DeviceState *dev)

{

    char path[30];



    snprintf(path, sizeof(path), "%s@%d", qdev_fw_name(dev),

             ((IDEBus*)dev->parent_bus)->bus_id);



    return strdup(path);

}
