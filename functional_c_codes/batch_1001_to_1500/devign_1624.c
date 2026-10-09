/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1624
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dbe94539469b6d5113b37ea45eaf69ddbe34154e
 */

static void opt_qscale(const char *arg)

{

    video_qscale = atof(arg);

    if (video_qscale <= 0 ||

        video_qscale > 255) {

        fprintf(stderr, "qscale must be > 0.0 and <= 255\n");

        ffmpeg_exit(1);

    }

}
