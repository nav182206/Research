/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3414
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2d0d2837dcf786da415cf4165d37f4ddd684ff57
 */

static int drive_init_func(QemuOpts *opts, void *opaque)

{

    int *use_scsi = opaque;



    return drive_init(opts, *use_scsi) == NULL;

}
