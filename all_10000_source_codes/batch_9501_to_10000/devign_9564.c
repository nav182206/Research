/* 
 * Benchmark Sample ID : devign_9564
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=35f9d8c20a26a7d383d3d36796e64a4b8987d743
 */

static int tta_get_unary(GetBitContext *gb)

{

    int ret = 0;



    // count ones

    while(get_bits1(gb))

        ret++;

    return ret;

}
