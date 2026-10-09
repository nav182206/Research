/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2151
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=111049a4ecefc9cf1ac75c773f4c5c165f27fe63
 */

void qmp_drive_backup(DriveBackup *arg, Error **errp)

{

    return do_drive_backup(arg, NULL, errp);

}
