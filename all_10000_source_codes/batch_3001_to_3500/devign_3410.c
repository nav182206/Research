/* 
 * Benchmark Sample ID : devign_3410
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=167c50d8f94e0ffb880aa5cd2a232a3f32f0df1d
 */

int target_to_host_signal(int sig)

{

    if (sig >= _NSIG)

        return sig;

    return target_to_host_signal_table[sig];

}
