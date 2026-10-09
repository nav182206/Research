/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1987
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ddb2dd7edbccc5596d8e3c039133be8444cb1d02
 */

static uint8_t lag_calc_zero_run(int8_t x)

{

    return (x << 1) ^ (x >> 7);

}
