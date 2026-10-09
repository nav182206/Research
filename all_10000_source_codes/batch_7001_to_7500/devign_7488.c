/* 
 * Benchmark Sample ID : devign_7488
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=65f3e33964bc4bb634d61463814a4ccca794e3c0
 */

static int iscsi_aio_discard_acb(IscsiAIOCB *acb) {

    struct iscsi_context *iscsi = acb->iscsilun->iscsi;

    struct unmap_list list[1];



    acb->canceled   = 0;

    acb->bh         = NULL;

    acb->status     = -EINPROGRESS;

    acb->buf        = NULL;



    list[0].lba = sector_qemu2lun(acb->sector_num, acb->iscsilun);

    list[0].num = acb->nb_sectors * BDRV_SECTOR_SIZE / acb->iscsilun->block_size;



    acb->task = iscsi_unmap_task(iscsi, acb->iscsilun->lun,

                                 0, 0, &list[0], 1,

                                 iscsi_unmap_cb,

                                 acb);

    if (acb->task == NULL) {

        error_report("iSCSI: Failed to send unmap command. %s",

                     iscsi_get_error(iscsi));

        return -1;

    }



    return 0;

}
