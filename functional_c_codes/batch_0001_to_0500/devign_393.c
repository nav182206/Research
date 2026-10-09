/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_393
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=70205f1799252c3363a5bb5ea7ea5df090f2c88f
 */

void check_values (eq2_param_t *par)

{

  /* yuck! floating point comparisons... */



  if ((par->c == 1.0) && (par->b == 0.0) && (par->g == 1.0)) {

    par->adjust = NULL;

  }

#if HAVE_MMX && HAVE_6REGS

  else if (par->g == 1.0 && ff_gCpuCaps.hasMMX) {

    par->adjust = &affine_1d_MMX;

  }

#endif

  else {

    par->adjust = &apply_lut;

  }

}
