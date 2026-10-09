/* 
 * Benchmark Sample ID : devign_7290
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c7f8d0f3a52b5ef8fdcd305cce438f67d7e06a9f
 */

static void pc_machine_device_post_plug_cb(HotplugHandler *hotplug_dev,

                                           DeviceState *dev, Error **errp)

{

    if (object_dynamic_cast(OBJECT(dev), TYPE_PC_DIMM)) {

        pc_dimm_post_plug(hotplug_dev, dev, errp);

    }

}
