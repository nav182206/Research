/* 
 * Benchmark Sample ID : devign_1393
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c6572fa0d2b81bc3a9ca5716f975f2bf59c62e6c
 */

int vhdx_log_write_and_flush(BlockDriverState *bs, BDRVVHDXState *s,

                             void *data, uint32_t length, uint64_t offset)

{

    int ret = 0;

    VHDXLogSequence logs = { .valid = true,

                             .count = 1,

                             .hdr = { 0 } };





    /* Make sure data written (new and/or changed blocks) is stable

     * on disk, before creating log entry */

    bdrv_flush(bs);

    ret = vhdx_log_write(bs, s, data, length, offset);

    if (ret < 0) {

        goto exit;

    }

    logs.log = s->log;



    /* Make sure log is stable on disk */

    bdrv_flush(bs);

    ret = vhdx_log_flush(bs, s, &logs);

    if (ret < 0) {

        goto exit;

    }



    s->log = logs.log;



exit:

    return ret;

}
