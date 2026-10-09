/* 
 * Benchmark Sample ID : devign_8956
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=318347234d7069b62d38391dd27e269a3107d668
 */

static void spapr_core_release(DeviceState *dev, void *opaque)

{

    HotplugHandler *hotplug_ctrl;



    hotplug_ctrl = qdev_get_hotplug_handler(dev);

    hotplug_handler_unplug(hotplug_ctrl, dev, &error_abort);

}
