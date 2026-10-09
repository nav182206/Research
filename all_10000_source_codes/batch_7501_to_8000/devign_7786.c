/* 
 * Benchmark Sample ID : devign_7786
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=622b520fb4ca50b5028485f1d225317ece0a42b9
 */

int scsi_bus_legacy_handle_cmdline(SCSIBus *bus)

{

    Location loc;

    DriveInfo *dinfo;

    int res = 0, unit;



    loc_push_none(&loc);

    for (unit = 0; unit < MAX_SCSI_DEVS; unit++) {

        dinfo = drive_get(IF_SCSI, bus->busnr, unit);

        if (dinfo == NULL) {

            continue;

        }

        qemu_opts_loc_restore(dinfo->opts);

        if (!scsi_bus_legacy_add_drive(bus, dinfo->bdrv, unit)) {

            res = -1;

            break;

        }

    }

    loc_pop(&loc);

    return res;

}
