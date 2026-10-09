/* 
 * Benchmark Sample ID : devign_7132
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=95b5edcd92d64c7b8fe9f2e3e0725fdf84be0dfa
 */

static int ide_drive_initfn(IDEDevice *dev)

{

    return ide_dev_initfn(dev,

                          bdrv_get_type_hint(dev->conf.bs) == BDRV_TYPE_CDROM

                          ? IDE_CD : IDE_HD);

}
