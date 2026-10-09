/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7527
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6e0d8c06c7af61859e8d7bc2351a607d8abeab75
 */

static void opt_qmax(const char *arg)

{

    video_qmax = atoi(arg);

    if (video_qmax < 0 ||

        video_qmax > 31) {

        fprintf(stderr, "qmax must be >= 1 and <= 31\n");

        exit(1);

    }

}
