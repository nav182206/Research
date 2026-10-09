/* 
 * Benchmark Sample ID : devign_6622
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4be746345f13e99e468c60acbd3a355e8183e3ce
 */

static uint32_t scsi_init_iovec(SCSIDiskReq *r, size_t size)

{

    SCSIDiskState *s = DO_UPCAST(SCSIDiskState, qdev, r->req.dev);



    if (!r->iov.iov_base) {

        r->buflen = size;

        r->iov.iov_base = qemu_blockalign(s->qdev.conf.bs, r->buflen);

    }

    r->iov.iov_len = MIN(r->sector_count * 512, r->buflen);

    qemu_iovec_init_external(&r->qiov, &r->iov, 1);

    return r->qiov.size / 512;

}
