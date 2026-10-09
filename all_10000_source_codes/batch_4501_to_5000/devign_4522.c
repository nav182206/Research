/* 
 * Benchmark Sample ID : devign_4522
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f36aec3b5e18c4c167612d0051a6d5b6144b3552
 */

static int mace3_decode_frame(AVCodecContext *avctx,

                              void *data, int *data_size,

                              const uint8_t *buf, int buf_size)

{

    int16_t *samples = data;

    MACEContext *ctx = avctx->priv_data;

    int i, j, k;



    for(i = 0; i < avctx->channels; i++) {

        int16_t *output = samples + i;



        for (j=0; j < buf_size / 2 / avctx->channels; j++)

            for (k=0; k < 2; k++) {

                uint8_t pkt = buf[i*2 + j*2*avctx->channels + k];

                chomp3(&ctx->chd[i], output, pkt       &7, MACEtab1, MACEtab2,

                       8, avctx->channels);

                output += avctx->channels;

                chomp3(&ctx->chd[i], output,(pkt >> 3) &3, MACEtab3, MACEtab4,

                       4, avctx->channels);

                output += avctx->channels;

                chomp3(&ctx->chd[i], output, pkt >> 5    , MACEtab1, MACEtab2,

                       8, avctx->channels);

                output += avctx->channels;

            }

    }



    *data_size = 2 * 3 * buf_size;



    return buf_size;

}
