/* 
 * Benchmark Sample ID : devign_2601
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c3c96deb5f8cbbdb700ba97920ceedddacb5dcb9
 */

static void fft_ref_init(int nbits, int inverse)

{

    int i, n = 1 << nbits;



    exptab = av_malloc((n / 2) * sizeof(*exptab));



    for (i = 0; i < (n/2); i++) {

        double alpha = 2 * M_PI * (float)i / (float)n;

        double c1 = cos(alpha), s1 = sin(alpha);

        if (!inverse)

            s1 = -s1;

        exptab[i].re = c1;

        exptab[i].im = s1;

    }

}
