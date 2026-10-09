/* 
 * Benchmark Sample ID : devign_2547
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1bd075f29ea6d11853475c7c42734595720c3ac6
 */

iscsi_synccache10_cb(struct iscsi_context *iscsi, int status,

                     void *command_data, void *opaque)

{

    IscsiAIOCB *acb = opaque;



    if (acb->canceled != 0) {

        qemu_aio_release(acb);

        scsi_free_scsi_task(acb->task);

        acb->task = NULL;

        return;

    }



    acb->status = 0;

    if (status < 0) {

        error_report("Failed to sync10 data on iSCSI lun. %s",

                     iscsi_get_error(iscsi));

        acb->status = -EIO;

    }



    iscsi_schedule_bh(acb);

    scsi_free_scsi_task(acb->task);

    acb->task = NULL;

}
