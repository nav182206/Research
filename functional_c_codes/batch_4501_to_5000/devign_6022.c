/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6022
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=318347234d7069b62d38391dd27e269a3107d668
 */

static void spapr_lmb_release(DeviceState *dev, void *opaque)

{

    HotplugHandler *hotplug_ctrl = qdev_get_hotplug_handler(dev);

    sPAPRMachineState *spapr = SPAPR_MACHINE(hotplug_ctrl);

    sPAPRDIMMState *ds = spapr_pending_dimm_unplugs_find(spapr, PC_DIMM(dev));



    if (--ds->nr_lmbs) {

        return;

    }



    spapr_pending_dimm_unplugs_remove(spapr, ds);



    /*

     * Now that all the LMBs have been removed by the guest, call the

     * pc-dimm unplug handler to cleanup up the pc-dimm device.

     */

    hotplug_handler_unplug(hotplug_ctrl, dev, &error_abort);

}
