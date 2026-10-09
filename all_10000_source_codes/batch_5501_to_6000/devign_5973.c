/* 
 * Benchmark Sample ID : devign_5973
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5def6b80e1eca696c1fc6099e7f4d36729686402
 */

static void raw_refresh_limits(BlockDriverState *bs, Error **errp)

{

    BDRVRawState *s = bs->opaque;

    struct stat st;



    if (!fstat(s->fd, &st)) {

        if (S_ISBLK(st.st_mode)) {

            int ret = hdev_get_max_transfer_length(s->fd);

            if (ret >= 0) {

                bs->bl.max_transfer_length = ret;

            }

        }

    }



    raw_probe_alignment(bs, s->fd, errp);

    bs->bl.min_mem_alignment = s->buf_align;

    bs->bl.opt_mem_alignment = MAX(s->buf_align, getpagesize());

}
