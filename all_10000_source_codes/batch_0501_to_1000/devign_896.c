/* 
 * Benchmark Sample ID : devign_896
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fb7b5c0df6e3c501973ce4d57eb2b1d4344a519d
 */

static void scsi_unrealize(SCSIDevice *s, Error **errp)

{

    scsi_device_purge_requests(s, SENSE_CODE(NO_SENSE));

    blockdev_mark_auto_del(s->conf.blk);

}
