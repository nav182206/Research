/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5572
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=65d21bc73bda6515fd9b4ff5b2e90454f7a0b419
 */

static int raw_pwrite_aligned(BlockDriverState *bs, int64_t offset,

                      const uint8_t *buf, int count)

{

    BDRVRawState *s = bs->opaque;

    int ret;



    ret = fd_open(bs);

    if (ret < 0)

        return -errno;



    ret = pwrite(s->fd, buf, count, offset);

    if (ret == count)

        goto label__raw_write__success;



    DEBUG_BLOCK_PRINT("raw_pwrite(%d:%s, %" PRId64 ", %p, %d) [%" PRId64

                      "] write failed %d : %d = %s\n",

                      s->fd, bs->filename, offset, buf, count,

                      bs->total_sectors, ret, errno, strerror(errno));



label__raw_write__success:



    return  (ret < 0) ? -errno : ret;

}
