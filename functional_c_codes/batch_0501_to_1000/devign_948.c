/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_948
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=27e0c9a1bbd166a67c16291016fba298a8e47140
 */

void ide_init2_with_non_qdev_drives(IDEBus *bus, DriveInfo *hd0,

                                    DriveInfo *hd1, qemu_irq irq)

{

    int i;

    DriveInfo *dinfo;



    for(i = 0; i < 2; i++) {

        dinfo = i == 0 ? hd0 : hd1;

        ide_init1(bus, i);

        if (dinfo) {

            if (ide_init_drive(&bus->ifs[i], dinfo->bdrv,

                               dinfo->media_cd ? IDE_CD : IDE_HD, NULL,

                               *dinfo->serial ? dinfo->serial : NULL) < 0) {

                error_report("Can't set up IDE drive %s", dinfo->id);

                exit(1);

            }

            bdrv_attach_dev_nofail(dinfo->bdrv, &bus->ifs[i]);

        } else {

            ide_reset(&bus->ifs[i]);

        }

    }

    bus->irq = irq;

    bus->dma = &ide_dma_nop;

}
