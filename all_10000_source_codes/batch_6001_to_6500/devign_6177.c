/* 
 * Benchmark Sample ID : devign_6177
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e823e7367754dd23de16a141c06471735a488f0d
 */

SwsVector *sws_getGaussianVec(double variance, double quality)

{

    const int length = (int)(variance * quality + 0.5) | 1;

    int i;

    double middle  = (length - 1) * 0.5;

    SwsVector *vec = sws_allocVec(length);



    if (!vec)

        return NULL;



    for (i = 0; i < length; i++) {

        double dist = i - middle;

        vec->coeff[i] = exp(-dist * dist / (2 * variance * variance)) /

                        sqrt(2 * variance * M_PI);

    }



    sws_normalizeVec(vec, 1.0);



    return vec;

}
