/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7942
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d8abfcb50a33aed369bbd267852cf04009c49e9
 */

aio_write_done(void *opaque, int ret)

{

	struct aio_ctx *ctx = opaque;

	struct timeval t2;



	gettimeofday(&t2, NULL);





	if (ret < 0) {

		printf("aio_write failed: %s\n", strerror(-ret));

		return;

	}



	if (ctx->qflag) {

		return;

	}



	/* Finally, report back -- -C gives a parsable format */

	t2 = tsub(t2, ctx->t1);

	print_report("wrote", &t2, ctx->offset, ctx->qiov.size,

		     ctx->qiov.size, 1, ctx->Cflag);



	qemu_io_free(ctx->buf);

	free(ctx);

}
