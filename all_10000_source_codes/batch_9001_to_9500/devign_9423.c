/* 
 * Benchmark Sample ID : devign_9423
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=29d1df66adb3723d1e7f2d363984b50792fb7c11
 */

static inline int l3_unscale(int value, int exponent)

{

    unsigned int m;

    int e;



    e  = table_4_3_exp  [4 * value + (exponent & 3)];

    m  = table_4_3_value[4 * value + (exponent & 3)];

    e -= exponent >> 2;

    assert(e >= 1);

    if (e > 31)

        return 0;

    m = (m + (1 << (e - 1))) >> e;



    return m;

}
