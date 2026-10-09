/* 
 * Benchmark Sample ID : devign_2484
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7ccb84a91618eda626b12ce83d62cfe678cfc58f
 */

restore_sigcontext(CPUM68KState *env, struct target_sigcontext *sc, int *pd0)

{

    int temp;



    __get_user(env->aregs[7], &sc->sc_usp);

    __get_user(env->dregs[1], &sc->sc_d1);

    __get_user(env->aregs[0], &sc->sc_a0);

    __get_user(env->aregs[1], &sc->sc_a1);

    __get_user(env->pc, &sc->sc_pc);

    __get_user(temp, &sc->sc_sr);

    env->sr = (env->sr & 0xff00) | (temp & 0xff);



    *pd0 = tswapl(sc->sc_d0);

}
