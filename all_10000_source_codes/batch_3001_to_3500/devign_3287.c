/* 
 * Benchmark Sample ID : devign_3287
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0c22311b56e66115675c4a96e4c78547886a4171
 */

static void opt_frame_pad_left(const char *arg)

{

    frame_padleft = atoi(arg);

    if (frame_padleft < 0) {

        fprintf(stderr, "Incorrect left pad size\n");

        av_exit(1);

    }

}
