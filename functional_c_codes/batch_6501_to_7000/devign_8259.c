/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8259
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2d0d2837dcf786da415cf4165d37f4ddd684ff57
 */

static void default_drive(int enable, int snapshot, int use_scsi,

                          BlockInterfaceType type, int index,

                          const char *optstr)

{

    QemuOpts *opts;



    if (type == IF_DEFAULT) {

        type = use_scsi ? IF_SCSI : IF_IDE;

    }



    if (!enable || drive_get_by_index(type, index)) {

        return;

    }



    opts = drive_add(type, index, NULL, optstr);

    if (snapshot) {

        drive_enable_snapshot(opts, NULL);

    }

    if (!drive_init(opts, use_scsi)) {

        exit(1);

    }

}
