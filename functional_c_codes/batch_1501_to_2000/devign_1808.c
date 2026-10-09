/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1808
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8b33d9eeba91422ee2d73b6936ad57262d18cf5a
 */

static void raw_aio_writev_scrubbed(void *opaque, int ret)

{

    RawScrubberBounce *b = opaque;



    if (ret < 0) {

        b->cb(b->opaque, ret);

    } else {

        b->cb(b->opaque, ret + 512);

    }



    qemu_iovec_destroy(&b->qiov);

    qemu_free(b);

}
