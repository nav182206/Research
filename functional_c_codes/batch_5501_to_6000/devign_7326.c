/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7326
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0008afc59c240271827d8a0fc747179da905050f
 */

static int dv_write_header(AVFormatContext *s)

{

    s->priv_data = dv_init_mux(s);

    if (!s->priv_data) {

        av_log(s, AV_LOG_ERROR, "Can't initialize DV format!\n"

                    "Make sure that you supply exactly two streams:\n"

                    "     video: 25fps or 29.97fps, audio: 2ch/48Khz/PCM\n"

                    "     (50Mbps allows an optional second audio stream)\n");

        return -1;

    }

    return 0;

}
