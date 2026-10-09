/* 
 * Benchmark Sample ID : devign_570
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a1bb73849fbd7d992b6ac2cf30c034244fb2299d
 */

void helper_rfdi(CPUPPCState *env)

{

    do_rfi(env, env->spr[SPR_BOOKE_DSRR0], SPR_BOOKE_DSRR1,

           ~((target_ulong)0x3FFF0000), 0);

}
