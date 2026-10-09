/* 
 * Benchmark Sample ID : devign_7647
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1d0817d56b66797118880358ea7d7a2acfdca429
 */

static float voice_factor(float *p_vector, float p_gain,

                          float *f_vector, float f_gain,

                          CELPMContext *ctx)

{

    double p_ener = (double) ctx->dot_productf(p_vector, p_vector,

                                                          AMRWB_SFR_SIZE) *

                    p_gain * p_gain;

    double f_ener = (double) ctx->dot_productf(f_vector, f_vector,

                                                          AMRWB_SFR_SIZE) *

                    f_gain * f_gain;



    return (p_ener - f_ener) / (p_ener + f_ener);

}
