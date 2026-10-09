/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_3474
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=979bea13003ef489d95d2538ac2fb1c26c6f103b
 */

int ff_dirac_parse_sequence_header(AVCodecContext *avctx, GetBitContext *gb,

                                   dirac_source_params *source)

{

    unsigned version_major;

    unsigned video_format, picture_coding_mode;



    version_major  = svq3_get_ue_golomb(gb);

    svq3_get_ue_golomb(gb); /* version_minor */

    avctx->profile = svq3_get_ue_golomb(gb);

    avctx->level   = svq3_get_ue_golomb(gb);

    video_format   = svq3_get_ue_golomb(gb);



    if (version_major < 2)

        av_log(avctx, AV_LOG_WARNING, "Stream is old and may not work\n");

    else if (version_major > 2)

        av_log(avctx, AV_LOG_WARNING, "Stream may have unhandled features\n");



    if (video_format > 20)

        return -1;



    // Fill in defaults for the source parameters.

    *source = dirac_source_parameters_defaults[video_format];



    // Override the defaults.

    if (parse_source_parameters(avctx, gb, source))

        return -1;



    if (av_image_check_size(source->width, source->height, 0, avctx))

        return -1;



    avcodec_set_dimensions(avctx, source->width, source->height);



    // currently only used to signal field coding

    picture_coding_mode = svq3_get_ue_golomb(gb);

    if (picture_coding_mode != 0) {

        av_log(avctx, AV_LOG_ERROR, "Unsupported picture coding mode %d",

               picture_coding_mode);

        return -1;

    }

    return 0;

}
