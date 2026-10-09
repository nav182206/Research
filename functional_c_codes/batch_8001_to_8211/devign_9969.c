/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9969
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=81cf8d8adc64203567e03326c13ea4abec9fe5df
 */

void helper_check_iow(CPUX86State *env, uint32_t t0)

{

    check_io(env, t0, 2);

}
