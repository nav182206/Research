/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5877
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c47ee043dc2cc85da710e87524144a720598c096
 */

void blk_eject(BlockBackend *blk, bool eject_flag)

{

    BlockDriverState *bs = blk_bs(blk);

    char *id;



    /* blk_eject is only called by qdevified devices */

    assert(!blk->legacy_dev);



    if (bs) {

        bdrv_eject(bs, eject_flag);



        id = blk_get_attached_dev_id(blk);

        qapi_event_send_device_tray_moved(blk_name(blk), id,

                                          eject_flag, &error_abort);

        g_free(id);



    }

}
