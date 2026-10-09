/* 
 * Benchmark Sample ID : devign_8227
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=120dc38f6113b676ecef0a2c9e42fc08cace5bdb
 */

void qdev_unplug(DeviceState *dev, Error **errp)

{

    DeviceClass *dc = DEVICE_GET_CLASS(dev);



    if (!dev->parent_bus->allow_hotplug) {

        error_set(errp, QERR_BUS_NO_HOTPLUG, dev->parent_bus->name);

        return;

    }

    assert(dc->unplug != NULL);



    qdev_hot_removed = true;



    if (dc->unplug(dev) < 0) {

        error_set(errp, QERR_UNDEFINED_ERROR);

        return;

    }

}
