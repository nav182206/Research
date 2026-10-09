/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6616
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d1adad3cca407f493c3637e20ecd4f7124e69212
 */

static void RENAME(lumRangeToJpeg)(int16_t *dst, int width)

{

    int i;

    for (i = 0; i < width; i++)

        dst[i] = (FFMIN(dst[i],30189)*19077 - 39057361)>>14;

}
