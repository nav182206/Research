/* 
 * Benchmark Sample ID : devign_9021
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=143685a42bbc8861b626457ce4cb8b1ce4b0c436
 */

static OSStatus ffat_encode_callback(AudioConverterRef converter, UInt32 *nb_packets,

                                     AudioBufferList *data,

                                     AudioStreamPacketDescription **packets,

                                     void *inctx)

{

    AVCodecContext *avctx = inctx;

    ATDecodeContext *at = avctx->priv_data;



    if (at->eof) {

        *nb_packets = 0;

        return 0;

    }



    av_frame_unref(&at->in_frame);

    av_frame_move_ref(&at->in_frame, &at->new_in_frame);



    if (!at->in_frame.data[0]) {

        *nb_packets = 0;

        return 1;

    }



    data->mNumberBuffers              = 1;

    data->mBuffers[0].mNumberChannels = avctx->channels;

    data->mBuffers[0].mDataByteSize   = at->in_frame.nb_samples *

                                        av_get_bytes_per_sample(avctx->sample_fmt) *

                                        avctx->channels;

    data->mBuffers[0].mData           = at->in_frame.data[0];

    if (*nb_packets > at->in_frame.nb_samples)

        *nb_packets = at->in_frame.nb_samples;



    return 0;

}
