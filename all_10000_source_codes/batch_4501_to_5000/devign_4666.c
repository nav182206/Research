/* 
 * Benchmark Sample ID : devign_4666
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=41b5e892b7dbf553b356b51004a6966233e71a6d
 */

static int print_drive(DeviceState *dev, Property *prop, char *dest, size_t len)

{

    DriveInfo **ptr = qdev_get_prop_ptr(dev, prop);

    return snprintf(dest, len, "%s", (*ptr)->id);

}
