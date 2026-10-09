/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5097
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dcd3418a35aab7ef283b68ed9997ce4ac204094e
 */

static int get_cv_ycbcr_matrix(AVCodecContext *avctx, CFStringRef *matrix) {

    switch(avctx->colorspace) {

        case AVCOL_SPC_BT709:

            *matrix = kCVImageBufferYCbCrMatrix_ITU_R_709_2;

            break;



        case AVCOL_SPC_UNSPECIFIED:

            *matrix = NULL;

            break;



        case AVCOL_SPC_BT470BG:

        case AVCOL_SPC_SMPTE170M:

            *matrix = kCVImageBufferYCbCrMatrix_ITU_R_601_4;

            break;



        case AVCOL_SPC_SMPTE240M:

            *matrix = kCVImageBufferYCbCrMatrix_SMPTE_240M_1995;

            break;



        case AVCOL_SPC_BT2020_NCL:

            *matrix = kCVImageBufferYCbCrMatrix_ITU_R_2020;

            break;



        default:

            av_log(avctx, AV_LOG_ERROR, "Color space %s is not supported.\n", av_color_space_name(avctx->colorspace));

            return -1;

    }



    return 0;

}
