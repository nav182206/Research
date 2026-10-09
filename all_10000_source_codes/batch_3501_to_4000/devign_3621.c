/* 
 * Benchmark Sample ID : devign_3621
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=024a6fbdb9d8cbc4d7f833b23db51c9d1004bc47
 */

int qdev_unplug(DeviceState *dev)

{

    if (!dev->parent_bus->allow_hotplug) {

        qerror_report(QERR_BUS_NO_HOTPLUG, dev->parent_bus->name);

        return -1;

    }

    assert(dev->info->unplug != NULL);



    if (dev->ref != 0) {

        qerror_report(QERR_DEVICE_IN_USE, dev->id?:"");

        return -1;

    }



    qdev_hot_removed = true;



    return dev->info->unplug(dev);

}
