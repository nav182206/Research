/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9052
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3954d33ab7f82f5a5fa0ced231849920265a5fec
 */

void spapr_vio_bus_register_withprop(VIOsPAPRDeviceInfo *info)

{

    info->qdev.init = spapr_vio_busdev_init;

    info->qdev.bus_info = &spapr_vio_bus_info;



    assert(info->qdev.size >= sizeof(VIOsPAPRDevice));

    qdev_register(&info->qdev);

}
