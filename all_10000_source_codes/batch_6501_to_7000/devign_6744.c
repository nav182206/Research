/* 
 * Benchmark Sample ID : devign_6744
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=857cd1f33bcf86005529af2a77f861f884327be5
 */

void swri_resample_dsp_init(ResampleContext *c)

{

#define FNIDX(fmt) (AV_SAMPLE_FMT_##fmt - AV_SAMPLE_FMT_S16P)

    c->dsp.resample_one[FNIDX(S16P)] = (resample_one_fn) resample_one_int16;

    c->dsp.resample_one[FNIDX(S32P)] = (resample_one_fn) resample_one_int32;

    c->dsp.resample_one[FNIDX(FLTP)] = (resample_one_fn) resample_one_float;

    c->dsp.resample_one[FNIDX(DBLP)] = (resample_one_fn) resample_one_double;



    c->dsp.resample_common[FNIDX(S16P)] = (resample_fn) resample_common_int16;

    c->dsp.resample_common[FNIDX(S32P)] = (resample_fn) resample_common_int32;

    c->dsp.resample_common[FNIDX(FLTP)] = (resample_fn) resample_common_float;

    c->dsp.resample_common[FNIDX(DBLP)] = (resample_fn) resample_common_double;



    c->dsp.resample_linear[FNIDX(S16P)] = (resample_fn) resample_linear_int16;

    c->dsp.resample_linear[FNIDX(S32P)] = (resample_fn) resample_linear_int32;

    c->dsp.resample_linear[FNIDX(FLTP)] = (resample_fn) resample_linear_float;

    c->dsp.resample_linear[FNIDX(DBLP)] = (resample_fn) resample_linear_double;



    if (ARCH_X86) swri_resample_dsp_x86_init(c);

}
