/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5515
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=031380d8770d2df6c386e4aeabd412007d3ebd54
 */

static void aio_write_done(void *opaque, int ret)

{

    struct aio_ctx *ctx = opaque;

    struct timeval t2;



    gettimeofday(&t2, NULL);





    if (ret < 0) {

        printf("aio_write failed: %s\n", strerror(-ret));

        goto out;

    }



    if (ctx->qflag) {

        goto out;

    }



    /* Finally, report back -- -C gives a parsable format */

    t2 = tsub(t2, ctx->t1);

    print_report("wrote", &t2, ctx->offset, ctx->qiov.size,

                 ctx->qiov.size, 1, ctx->Cflag);

out:

    qemu_io_free(ctx->buf);

    free(ctx);

}
