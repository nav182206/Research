/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1362
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f0f2babca23a3d099bcd5a1e18cf5d0eae2f4ef3
 */

static void zero_remaining(unsigned int b, unsigned int b_max,

                           const unsigned int *div_blocks, int32_t *buf)

{

    unsigned int count = 0;



    while (b < b_max)

        count += div_blocks[b];



    if (count)

        memset(buf, 0, sizeof(*buf) * count);

}
