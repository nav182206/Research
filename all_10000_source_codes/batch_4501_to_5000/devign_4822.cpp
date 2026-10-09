/* 
 * Benchmark Sample ID : devign_4822
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2753d4a5fa44d980cc6a279f323a12ca8d172972
 */

static void drive_uninit(DriveInfo *dinfo)

{

    qemu_opts_del(dinfo->opts);

    bdrv_delete(dinfo->bdrv);


    QTAILQ_REMOVE(&drives, dinfo, next);

    qemu_free(dinfo);

}
