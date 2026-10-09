/* 
 * Benchmark Sample ID : devign_4751
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6e0d8c06c7af61859e8d7bc2351a607d8abeab75
 */

static void opt_qmin(const char *arg)

{

    video_qmin = atoi(arg);

    if (video_qmin < 0 ||

        video_qmin > 31) {

        fprintf(stderr, "qmin must be >= 1 and <= 31\n");

        exit(1);

    }

}
