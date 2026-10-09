/* 
 * Benchmark Sample ID : devign_8485
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b1ade3d1821a29174963b28cd0caa5f7ed394998
 */

void ff_celp_lp_synthesis_filterf(float *out,

                                  const float* filter_coeffs,

                                  const float* in,

                                  int buffer_length,

                                  int filter_length)

{

    int i,n;



    // Avoids a +1 in the inner loop.

    filter_length++;



    for (n = 0; n < buffer_length; n++) {

        out[n] = in[n];

        for (i = 1; i < filter_length; i++)

            out[n] -= filter_coeffs[i-1] * out[n-i];

    }

}
