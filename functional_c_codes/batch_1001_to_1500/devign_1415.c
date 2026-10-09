/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1415
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=42da8ea8e848e65611f0c606cd2c96d3a70c041d
 */

static int latm_decode_frame(AVCodecContext *avctx, void *out, int *out_size,

                             AVPacket *avpkt)

{

    struct LATMContext *latmctx = avctx->priv_data;

    int                 muxlength, err;

    GetBitContext       gb;



    if (avpkt->size == 0)

        return 0;



    init_get_bits(&gb, avpkt->data, avpkt->size * 8);



    // check for LOAS sync word

    if (get_bits(&gb, 11) != LOAS_SYNC_WORD)

        return AVERROR_INVALIDDATA;



    muxlength = get_bits(&gb, 13) + 3;

    // not enough data, the parser should have sorted this

    if (muxlength > avpkt->size)

        return AVERROR_INVALIDDATA;



    if ((err = read_audio_mux_element(latmctx, &gb)) < 0)

        return err;



    if (!latmctx->initialized) {

        if (!avctx->extradata) {

            *out_size = 0;

            return avpkt->size;

        } else {


            if ((err = aac_decode_init(avctx)) < 0)

                return err;

            latmctx->initialized = 1;

        }

    }



    if (show_bits(&gb, 12) == 0xfff) {

        av_log(latmctx->aac_ctx.avctx, AV_LOG_ERROR,

               "ADTS header detected, probably as result of configuration "

               "misparsing\n");

        return AVERROR_INVALIDDATA;

    }



    if ((err = aac_decode_frame_int(avctx, out, out_size, &gb)) < 0)

        return err;



    return muxlength;

}
