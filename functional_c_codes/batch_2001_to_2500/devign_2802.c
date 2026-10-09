/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2802
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f42b3195d3f2692a4dfc0a8668bb4ac35301f2ed
 */

static void fix_bitshift(ShortenContext *s, int32_t *buffer)

{

    int i;



    if (s->bitshift != 0)

        for (i = 0; i < s->blocksize; i++)

            buffer[s->nwrap + i] <<= s->bitshift;

}
