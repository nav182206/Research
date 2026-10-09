/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7201
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

static void do_commit(Monitor *mon, const QDict *qdict)

{

    int all_devices;

    DriveInfo *dinfo;

    const char *device = qdict_get_str(qdict, "device");



    all_devices = !strcmp(device, "all");

    TAILQ_FOREACH(dinfo, &drives, next) {

        if (!all_devices)

            if (strcmp(bdrv_get_device_name(dinfo->bdrv), device))

                continue;

        bdrv_commit(dinfo->bdrv);

    }

}
