/* 
 * Benchmark Sample ID : devign_7478
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8194f35a0c71a3bf169459bf715bea53b7bbc904
 */

void helper_retry(void)

{

    env->pc = env->tsptr->tpc;

    env->npc = env->tsptr->tnpc;

    PUT_CCR(env, env->tsptr->tstate >> 32);

    env->asi = (env->tsptr->tstate >> 24) & 0xff;

    change_pstate((env->tsptr->tstate >> 8) & 0xf3f);

    PUT_CWP64(env, env->tsptr->tstate & 0xff);

    env->tl--;

    env->tsptr = &env->ts[env->tl & MAXTL_MASK];

}
