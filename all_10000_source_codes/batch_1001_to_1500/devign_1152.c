/* 
 * Benchmark Sample ID : devign_1152
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=38152d9368beb080b4acd6cd9e5ccc89b3f733bf
 */

static void dss_sp_scale_vector(int32_t *vec, int bits, int size)

{

    int i;



    if (bits < 0)

        for (i = 0; i < size; i++)

            vec[i] = vec[i] >> -bits;

    else

        for (i = 0; i < size; i++)

            vec[i] = vec[i] << bits;

}
