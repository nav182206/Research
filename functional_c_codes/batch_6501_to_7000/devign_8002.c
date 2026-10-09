/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8002
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static void spapr_create_nvram(sPAPREnvironment *spapr)

{

    DeviceState *dev = qdev_create(&spapr->vio_bus->bus, "spapr-nvram");

    DriveInfo *dinfo = drive_get(IF_PFLASH, 0, 0);



    if (dinfo) {

        qdev_prop_set_drive_nofail(dev, "drive",

                                   blk_bs(blk_by_legacy_dinfo(dinfo)));

    }



    qdev_init_nofail(dev);



    spapr->nvram = (struct sPAPRNVRAM *)dev;

}
