/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2855
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e53c9065ca08a9153ecc73a6a8940bcc6d667e58
 */

static void fill_float_array(AVLFG *lfg, float *a, int len)

{

    int i;

    double bmg[2], stddev = 10.0, mean = 0.0;



    for (i = 0; i < len; i += 2) {

        av_bmg_get(lfg, bmg);

        a[i]     = bmg[0] * stddev + mean;

        a[i + 1] = bmg[1] * stddev + mean;

    }

}
