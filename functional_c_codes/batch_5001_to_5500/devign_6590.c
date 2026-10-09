/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6590
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7c36ee216f1e668e2c2af1573bd9dbbb2a501f48
 */

static void sbr_qmf_deint_bfly_c(INTFLOAT *v, const INTFLOAT *src0, const INTFLOAT *src1)

{

    int i;

    for (i = 0; i < 64; i++) {

        v[      i] = AAC_SRA_R((src0[i] - src1[63 - i]), 5);

        v[127 - i] = AAC_SRA_R((src0[i] + src1[63 - i]), 5);

    }

}
