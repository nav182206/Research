/* 
 * Benchmark Sample ID : devign_9565
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2374e73edafff0586cbfb67c333c5a7588f81fd5
 */

void helper_set_alt_mode (void)

{

    env->saved_mode = env->ps & 0xC;

    env->ps = (env->ps & ~0xC) | (env->ipr[IPR_ALT_MODE] & 0xC);

}
