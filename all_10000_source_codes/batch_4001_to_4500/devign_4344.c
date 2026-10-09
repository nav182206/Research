/* 
 * Benchmark Sample ID : devign_4344
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=69c23e6f33c38ebc03ce7f51fcb963deaff7383b
 */

static void prodsum(float *tgt, float *src, int len, int n)

{

    unsigned int x;

    float *p1, *p2;

    double sum;



    while (n >= 0) {

        p1 = (p2 = src) - n;

        for (sum=0, x=len; x--; sum += (*p1++) * (*p2++));

        tgt[n--] = sum;

    }

}
