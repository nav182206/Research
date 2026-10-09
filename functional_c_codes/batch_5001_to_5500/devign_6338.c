/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6338
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b8b8e82ea14016b2cb04b49ecea57f836e6ee7f8
 */

static int dnxhd_decode_row(AVCodecContext *avctx, void *data,

                            int rownb, int threadnb)

{

    const DNXHDContext *ctx = avctx->priv_data;

    uint32_t offset = ctx->mb_scan_index[rownb];

    RowContext *row = ctx->rows + threadnb;

    int x;



    row->last_dc[0] =

    row->last_dc[1] =

    row->last_dc[2] = 1 << (ctx->bit_depth + 2); // for levels +2^(bitdepth-1)

    init_get_bits(&row->gb, ctx->buf + offset, (ctx->buf_size - offset) << 3);

    for (x = 0; x < ctx->mb_width; x++) {

        //START_TIMER;

        dnxhd_decode_macroblock(ctx, row, data, x, rownb);

        //STOP_TIMER("decode macroblock");

    }



    return 0;

}
