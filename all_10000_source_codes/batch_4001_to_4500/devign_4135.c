/* 
 * Benchmark Sample ID : devign_4135
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=81cf8d8adc64203567e03326c13ea4abec9fe5df
 */

void helper_check_iob(CPUX86State *env, uint32_t t0)

{

    check_io(env, t0, 1);

}
