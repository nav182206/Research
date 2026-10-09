/* 
 * Benchmark Sample ID : devign_7538
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1eb1f6f281eb6036d363e0317c1500be4a2708f2
 */

static int dot_product(const int16_t *a, const int16_t *b, int length)

{

    int i, sum = 0;



    for (i = 0; i < length; i++) {

        int64_t prod = av_clipl_int32(MUL64(a[i], b[i]) << 1);

        sum = av_clipl_int32(sum + prod);

    }

    return sum;

}
