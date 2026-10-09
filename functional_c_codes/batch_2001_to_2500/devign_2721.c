/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2721
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1cb0edb40b8e94e1a50ad40c40d43e34ed8435fe
 */

int avcodec_decode_video(AVCodecContext *avctx, AVPicture *picture, 

                         int *got_picture_ptr,

                         UINT8 *buf, int buf_size)

{

    int ret;



    ret = avctx->codec->decode(avctx, picture, got_picture_ptr, 

                               buf, buf_size);

    avctx->frame_number++;

    return ret;

}
