/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8421
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f1f57066573e832438cd87600310589fa9cee202
 */

void blk_dev_change_media_cb(BlockBackend *blk, bool load)

{

    if (blk->dev_ops && blk->dev_ops->change_media_cb) {

        bool tray_was_closed = !blk_dev_is_tray_open(blk);



        blk->dev_ops->change_media_cb(blk->dev_opaque, load);

        if (tray_was_closed) {

            /* tray open */

            qapi_event_send_device_tray_moved(blk_name(blk),

                                              true, &error_abort);

        }

        if (load) {

            /* tray close */

            qapi_event_send_device_tray_moved(blk_name(blk),

                                              false, &error_abort);

        }

    }

}
