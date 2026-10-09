/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4014
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f8b6cc0070aab8b75bd082582c829be1353f395f
 */

void qdev_prop_set_drive(DeviceState *dev, const char *name, DriveInfo *value)

{

    qdev_prop_set(dev, name, &value, PROP_TYPE_DRIVE);

}
