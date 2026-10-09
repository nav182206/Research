/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8036
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7631f14bb35e8467d4ffaaa2b34e60614eb37c71
 */

static int get_aac_sample_rates(AVFormatContext *s, AVCodecParameters *par,

                                int *sample_rate, int *output_sample_rate)

{

    MPEG4AudioConfig mp4ac;



    if (avpriv_mpeg4audio_get_config(&mp4ac, par->extradata,

                                     par->extradata_size * 8, 1) < 0) {

        av_log(s, AV_LOG_ERROR,

               "Error parsing AAC extradata, unable to determine samplerate.\n");

        return AVERROR(EINVAL);

    }



    *sample_rate        = mp4ac.sample_rate;

    *output_sample_rate = mp4ac.ext_sample_rate;

    return 0;

}
