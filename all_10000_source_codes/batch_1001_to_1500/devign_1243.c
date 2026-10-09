/* 
 * Benchmark Sample ID : devign_1243
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5ef19590802f000299e418143fc2301e3f43affe
 */

int show_bsfs(void *optctx, const char *opt, const char *arg)

{

    AVBitStreamFilter *bsf = NULL;



    printf("Bitstream filters:\n");

    while ((bsf = av_bitstream_filter_next(bsf)))

        printf("%s\n", bsf->name);

    printf("\n");

    return 0;

}
