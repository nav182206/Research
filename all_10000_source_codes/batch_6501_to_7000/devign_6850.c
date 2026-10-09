/* 
 * Benchmark Sample ID : devign_6850
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cc276c85d15272df6e44fb3252657a43cbd49555
 */

int64_t avcodec_guess_channel_layout(int nb_channels, enum CodecID codec_id, const char *fmt_name)

{

    switch(nb_channels) {

    case 1: return AV_CH_LAYOUT_MONO;

    case 2: return AV_CH_LAYOUT_STEREO;

    case 3: return AV_CH_LAYOUT_SURROUND;

    case 4: return AV_CH_LAYOUT_QUAD;

    case 5: return AV_CH_LAYOUT_5POINT0;

    case 6: return AV_CH_LAYOUT_5POINT1;

    case 8: return AV_CH_LAYOUT_7POINT1;

    default: return 0;

    }

}
