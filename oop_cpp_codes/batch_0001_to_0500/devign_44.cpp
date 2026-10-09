/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_44
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b097cc52fc9126bd1a71dae8302b8536d28104dd
 */

void acpi_memory_plug_cb(HotplugHandler *hotplug_dev, MemHotplugState *mem_st,

                         DeviceState *dev, Error **errp)

{

    MemStatus *mdev;

    DeviceClass *dc = DEVICE_GET_CLASS(dev);



    if (!dc->hotpluggable) {

        return;

    }



    mdev = acpi_memory_slot_status(mem_st, dev, errp);

    if (!mdev) {

        return;

    }



    mdev->dimm = dev;

    mdev->is_enabled = true;

    if (dev->hotplugged) {

        mdev->is_inserting = true;

        acpi_send_event(DEVICE(hotplug_dev), ACPI_MEMORY_HOTPLUG_STATUS);

    }

}
