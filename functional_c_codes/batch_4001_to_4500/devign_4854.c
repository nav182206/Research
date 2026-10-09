/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4854
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c9e884f3d98df85bf7f2cf30d71877b22929fdcb
 */

static int tm2_read_deltas(TM2Context *ctx, int stream_id)

{

    int d, mb;

    int i, v;



    d  = get_bits(&ctx->gb, 9);

    mb = get_bits(&ctx->gb, 5);



    av_assert2(mb < 32);

    if ((d < 1) || (d > TM2_DELTAS) || (mb < 1)) {

        av_log(ctx->avctx, AV_LOG_ERROR, "Incorrect delta table: %i deltas x %i bits\n", d, mb);

        return AVERROR_INVALIDDATA;

    }



    for (i = 0; i < d; i++) {

        v = get_bits_long(&ctx->gb, mb);

        if (v & (1 << (mb - 1)))

            ctx->deltas[stream_id][i] = v - (1 << mb);

        else

            ctx->deltas[stream_id][i] = v;

    }

    for (; i < TM2_DELTAS; i++)

        ctx->deltas[stream_id][i] = 0;



    return 0;

}
