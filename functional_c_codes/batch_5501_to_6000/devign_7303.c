/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7303
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a818a4b69d47ca3826dee36878074395aeac2083
 */

static int scsi_cd_initfn(SCSIDevice *dev)

{

    SCSIDiskState *s = DO_UPCAST(SCSIDiskState, qdev, dev);

    s->qdev.blocksize = 2048;

    s->qdev.type = TYPE_ROM;

    s->features |= 1 << SCSI_DISK_F_REMOVABLE;

    if (!s->product) {

        s->product = g_strdup("QEMU CD-ROM");

    }

    return scsi_initfn(&s->qdev);

}
