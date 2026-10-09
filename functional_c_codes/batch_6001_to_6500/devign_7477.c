/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7477
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d8abfcb50a33aed369bbd267852cf04009c49e9
 */

aio_read_done(void *opaque, int ret)

{

	struct aio_ctx *ctx = opaque;

	struct timeval t2;



	gettimeofday(&t2, NULL);



	if (ret < 0) {

		printf("readv failed: %s\n", strerror(-ret));

		return;

	}



	if (ctx->Pflag) {

		void *cmp_buf = malloc(ctx->qiov.size);



		memset(cmp_buf, ctx->pattern, ctx->qiov.size);

		if (memcmp(ctx->buf, cmp_buf, ctx->qiov.size)) {

			printf("Pattern verification failed at offset %lld, "

				"%zd bytes\n",

				(long long) ctx->offset, ctx->qiov.size);

		}

		free(cmp_buf);

	}



	if (ctx->qflag) {

		return;

	}



	if (ctx->vflag) {

		dump_buffer(ctx->buf, ctx->offset, ctx->qiov.size);

	}



	/* Finally, report back -- -C gives a parsable format */

	t2 = tsub(t2, ctx->t1);

	print_report("read", &t2, ctx->offset, ctx->qiov.size,

		     ctx->qiov.size, 1, ctx->Cflag);



	qemu_io_free(ctx->buf);

	free(ctx);

}
