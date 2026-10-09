/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7884
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=507dce2536fea4b78a9f4973f77e1fa20cfe1b81
 */

void ff_rv34dsp_init_neon(RV34DSPContext *c, DSPContext* dsp)

{

    c->rv34_inv_transform    = ff_rv34_inv_transform_noround_neon;

    c->rv34_inv_transform_dc = ff_rv34_inv_transform_noround_dc_neon;



    c->rv34_idct_add    = ff_rv34_idct_add_neon;

    c->rv34_idct_dc_add = ff_rv34_idct_dc_add_neon;

}
