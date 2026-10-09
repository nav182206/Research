/* 
 * Benchmark Sample ID : devign_6733
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c914c99d4b8159d6be7c53c21f63d84f24d5ffeb
 */

SwsVector *sws_cloneVec(SwsVector *a)

{

    int i;

    SwsVector *vec = sws_allocVec(a->length);



    if (!vec)

        return NULL;



    for (i = 0; i < a->length; i++)

        vec->coeff[i] = a->coeff[i];



    return vec;

}
