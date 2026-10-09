/* 
 * Benchmark Sample ID : devign_3677
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e701cd96c2d5dc034e7615967d208db3d953e111
 */

unsigned avutil_version(void)

{

    av_assert0(AV_PIX_FMT_VDA_VLD == 81); //check if the pix fmt enum has not had anything inserted or removed by mistake

    av_assert0(AV_SAMPLE_FMT_DBLP == 9);

    av_assert0(AVMEDIA_TYPE_ATTACHMENT == 4);

    av_assert0(AV_PICTURE_TYPE_BI == 7);

    av_assert0(LIBAVUTIL_VERSION_MICRO >= 100);

    av_assert0(HAVE_MMX2 == HAVE_MMXEXT);



    if (av_sat_dadd32(1, 2) != 5) {

        av_log(NULL, AV_LOG_FATAL, "Libavutil has been build with a broken binutils, please upgrade binutils and rebuild\n");

        abort();

    }



    ff_check_pixfmt_descriptors();



    return LIBAVUTIL_VERSION_INT;

}
