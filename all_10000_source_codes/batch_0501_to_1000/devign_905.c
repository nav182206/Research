/* 
 * Benchmark Sample ID : devign_905
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a03ef88f77af045a2eb9629b5ce774a3fb973c5e
 */

vpc_co_pwritev(BlockDriverState *bs, uint64_t offset, uint64_t bytes,

               QEMUIOVector *qiov, int flags)

{

    BDRVVPCState *s = bs->opaque;

    int64_t image_offset;

    int64_t n_bytes;

    int64_t bytes_done = 0;

    int ret;

    VHDFooter *footer =  (VHDFooter *) s->footer_buf;

    QEMUIOVector local_qiov;



    if (be32_to_cpu(footer->type) == VHD_FIXED) {

        return bdrv_co_pwritev(bs->file->bs, offset, bytes, qiov, 0);

    }



    qemu_co_mutex_lock(&s->lock);

    qemu_iovec_init(&local_qiov, qiov->niov);



    while (bytes > 0) {

        image_offset = get_image_offset(bs, offset, true);

        n_bytes = MIN(bytes, s->block_size - (offset % s->block_size));



        if (image_offset == -1) {

            image_offset = alloc_block(bs, offset);

            if (image_offset < 0) {

                ret = image_offset;

                goto fail;

            }

        }



        qemu_iovec_reset(&local_qiov);

        qemu_iovec_concat(&local_qiov, qiov, bytes_done, n_bytes);



        ret = bdrv_co_pwritev(bs->file->bs, image_offset, n_bytes,

                              &local_qiov, 0);

        if (ret < 0) {

            goto fail;

        }



        bytes -= n_bytes;

        offset += n_bytes;

        bytes_done += n_bytes;

    }



    ret = 0;

fail:

    qemu_iovec_destroy(&local_qiov);

    qemu_co_mutex_unlock(&s->lock);



    return ret;

}
