/* 
 * Benchmark Sample ID : devign_9566
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=41ecc72ba5932381208e151bf2d2149a0342beff
 */

setup_sigcontext(struct target_sigcontext *sc, CPUM68KState *env,

                 abi_ulong mask)

{

    int err = 0;



    __put_user(mask, &sc->sc_mask);

    __put_user(env->aregs[7], &sc->sc_usp);

    __put_user(env->dregs[0], &sc->sc_d0);

    __put_user(env->dregs[1], &sc->sc_d1);

    __put_user(env->aregs[0], &sc->sc_a0);

    __put_user(env->aregs[1], &sc->sc_a1);

    __put_user(env->sr, &sc->sc_sr);

    __put_user(env->pc, &sc->sc_pc);



    return err;

}
