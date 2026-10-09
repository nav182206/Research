/* 
 * Benchmark Sample ID : devign_2719
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=971d12b7f9d7be3ca8eb98e6c04ed521f83cbd3c
 */

int64_t av_gcd(int64_t a, int64_t b)

{

    if (b)

        return av_gcd(b, a % b);

    else

        return a;

}
