/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9705
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=016d2e1dfa21b64a524d3629fdd317d4c25bc3b8
 */

restore_sigcontext(CPUM68KState *env, struct target_sigcontext *sc, int *pd0)

{

    int err = 0;

    int temp;



    __get_user(env->aregs[7], &sc->sc_usp);

    __get_user(env->dregs[1], &sc->sc_d1);

    __get_user(env->aregs[0], &sc->sc_a0);

    __get_user(env->aregs[1], &sc->sc_a1);

    __get_user(env->pc, &sc->sc_pc);

    __get_user(temp, &sc->sc_sr);

    env->sr = (env->sr & 0xff00) | (temp & 0xff);



    *pd0 = tswapl(sc->sc_d0);



    return err;

}
