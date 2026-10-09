/* 
 * Benchmark Sample ID : devign_6019
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6e0d8c06c7af61859e8d7bc2351a607d8abeab75
 */

static void opt_mb_qmin(const char *arg)

{

    video_mb_qmin = atoi(arg);

    if (video_mb_qmin < 0 ||

        video_mb_qmin > 31) {

        fprintf(stderr, "qmin must be >= 1 and <= 31\n");

        exit(1);

    }

}
