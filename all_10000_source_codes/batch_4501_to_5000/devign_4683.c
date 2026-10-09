/* 
 * Benchmark Sample ID : devign_4683
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f51074cdc6e750daa3b6df727d83449a7e42b391
 */

void hmp_drive_add(Monitor *mon, const QDict *qdict)

{

    DriveInfo *dinfo = NULL;

    const char *opts = qdict_get_str(qdict, "opts");



    dinfo = add_init_drive(opts);

    if (!dinfo) {

        goto err;

    }

    if (dinfo->devaddr) {

        monitor_printf(mon, "Parameter addr not supported\n");

        goto err;

    }



    switch (dinfo->type) {

    case IF_NONE:

        monitor_printf(mon, "OK\n");

        break;

    default:

        if (pci_drive_hot_add(mon, qdict, dinfo)) {

            goto err;

        }

    }

    return;



err:

    if (dinfo) {

        blk_unref(blk_by_legacy_dinfo(dinfo));

    }

}
