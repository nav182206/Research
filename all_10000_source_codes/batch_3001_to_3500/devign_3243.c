/* 
 * Benchmark Sample ID : devign_3243
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=486637af8ef29ec215e0e0b7ecd3b5470f0e04e5
 */

static inline float to_float(uint8_t exp, int16_t mantissa)

{

    return ((float) (mantissa * scale_factors[exp]));

}
