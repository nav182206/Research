/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4418
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a818a4b69d47ca3826dee36878074395aeac2083
 */

static void scsi_destroy(SCSIDevice *s)

{

    scsi_device_purge_requests(s, SENSE_CODE(NO_SENSE));

    blockdev_mark_auto_del(s->conf.bs);

}
