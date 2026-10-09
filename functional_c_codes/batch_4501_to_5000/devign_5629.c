/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5629
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=788cf9f8c8cbda53843e060540f3e91a060eb744
 */

int monitor_read_block_device_key(Monitor *mon, const char *device,

                                  BlockCompletionFunc *completion_cb,

                                  void *opaque)

{

    Error *err = NULL;

    BlockBackend *blk;



    blk = blk_by_name(device);

    if (!blk) {

        monitor_printf(mon, "Device not found %s\n", device);

        return -1;

    }

    if (!blk_bs(blk)) {

        monitor_printf(mon, "Device '%s' has no medium\n", device);

        return -1;

    }



    bdrv_add_key(blk_bs(blk), NULL, &err);

    if (err) {

        error_free(err);

        return monitor_read_bdrv_key_start(mon, blk_bs(blk), completion_cb, opaque);

    }



    if (completion_cb) {

        completion_cb(opaque, 0);

    }

    return 0;

}
