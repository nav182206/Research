/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7074
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=931da6a5e9dd54563fe5d4d30b7bd4d0a0218c87
 */

uint32_t avpriv_fmt_ff2v4l(enum AVPixelFormat pix_fmt, enum AVCodecID codec_id)

{

    int i;



    for (i = 0; avpriv_fmt_conversion_table[i].codec_id != AV_CODEC_ID_NONE; i++) {

        if ((codec_id == AV_CODEC_ID_NONE ||

             avpriv_fmt_conversion_table[i].codec_id == codec_id) &&

            (pix_fmt == AV_PIX_FMT_NONE ||

             avpriv_fmt_conversion_table[i].ff_fmt == pix_fmt)) {

            return avpriv_fmt_conversion_table[i].v4l2_fmt;

        }

    }



    return 0;

}
