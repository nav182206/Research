/* 
 * Benchmark Sample ID : devign_217
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=92da23093c784b1d9f0db4db51d28ea80a59e759
 */

static inline int coeff_unpack_golomb(GetBitContext *gb, int qfactor, int qoffset)

{

    int coeff = dirac_get_se_golomb(gb);

    const int sign = FFSIGN(coeff);

    if (coeff)

        coeff = sign*((sign * coeff * qfactor + qoffset) >> 2);

    return coeff;

}
