/* 
 * Benchmark Sample ID : devign_9363
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6d1270a0f9ededd37ed14bde52b8ee69b99e8a7f
 */

int attribute_align_arg avcodec_decode_audio3(AVCodecContext *avctx, int16_t *samples,

                                              int *frame_size_ptr,

                                              AVPacket *avpkt)

{

    AVFrame frame;

    int ret, got_frame = 0;



    if (avctx->get_buffer != avcodec_default_get_buffer) {

        av_log(avctx, AV_LOG_ERROR, "Custom get_buffer() for use with"

                                    "avcodec_decode_audio3() detected. Overriding with avcodec_default_get_buffer\n");

        av_log(avctx, AV_LOG_ERROR, "Please port your application to "

                                    "avcodec_decode_audio4()\n");

        avctx->get_buffer = avcodec_default_get_buffer;

    }



    ret = avcodec_decode_audio4(avctx, &frame, &got_frame, avpkt);



    if (ret >= 0 && got_frame) {

        int ch, plane_size;

        int planar    = av_sample_fmt_is_planar(avctx->sample_fmt);

        int data_size = av_samples_get_buffer_size(&plane_size, avctx->channels,

                                                   frame.nb_samples,

                                                   avctx->sample_fmt, 1);

        if (*frame_size_ptr < data_size) {

            av_log(avctx, AV_LOG_ERROR, "output buffer size is too small for "

                                        "the current frame (%d < %d)\n", *frame_size_ptr, data_size);

            return AVERROR(EINVAL);

        }



        memcpy(samples, frame.extended_data[0], plane_size);



        if (planar && avctx->channels > 1) {

            uint8_t *out = ((uint8_t *)samples) + plane_size;

            for (ch = 1; ch < avctx->channels; ch++) {

                memcpy(out, frame.extended_data[ch], plane_size);

                out += plane_size;

            }

        }

        *frame_size_ptr = data_size;

    } else {

        *frame_size_ptr = 0;

    }

    return ret;

}
