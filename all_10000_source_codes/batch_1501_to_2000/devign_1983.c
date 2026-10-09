/* 
 * Benchmark Sample ID : devign_1983
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e829b0bb054ed3389e5b22dad61875e51674e629
 */

iscsi_connect_cb(struct iscsi_context *iscsi, int status, void *command_data,

                 void *opaque)

{

    struct IscsiTask *itask = opaque;

    struct scsi_task *task;



    if (status != 0) {

        itask->status   = 1;

        itask->complete = 1;

        return;

    }



    task = iscsi_inquiry_task(iscsi, itask->iscsilun->lun,

                              0, 0, 36,

                              iscsi_inquiry_cb, opaque);

    if (task == NULL) {

        error_report("iSCSI: failed to send inquiry command.");

        itask->status   = 1;

        itask->complete = 1;

        return;

    }

}
