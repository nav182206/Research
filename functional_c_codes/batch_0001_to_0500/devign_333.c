/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_333
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

void qdev_prop_set_drive_nofail(DeviceState *dev, const char *name,

                                BlockDriverState *value)

{

    if (qdev_prop_set_drive(dev, name, value) < 0) {

        exit(1);

    }

}
