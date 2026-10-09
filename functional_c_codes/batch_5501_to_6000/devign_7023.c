/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7023
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ea8de109af46ae8e6751217977ae8f7becf94ba5
 */

AVFilterFormats *avfilter_make_all_channel_layouts(void)

{

    static int64_t chlayouts[] = {

        AV_CH_LAYOUT_MONO,

        AV_CH_LAYOUT_STEREO,

        AV_CH_LAYOUT_4POINT0,

        AV_CH_LAYOUT_QUAD,

        AV_CH_LAYOUT_5POINT0,

        AV_CH_LAYOUT_5POINT0_BACK,

        AV_CH_LAYOUT_5POINT1,

        AV_CH_LAYOUT_5POINT1_BACK,

        AV_CH_LAYOUT_5POINT1|AV_CH_LAYOUT_STEREO_DOWNMIX,

        AV_CH_LAYOUT_7POINT1,

        AV_CH_LAYOUT_7POINT1_WIDE,

        AV_CH_LAYOUT_7POINT1|AV_CH_LAYOUT_STEREO_DOWNMIX,

        -1,

    };



    return avfilter_make_format64_list(chlayouts);

}
