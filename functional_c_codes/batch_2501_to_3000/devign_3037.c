/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3037
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c599d4d6d6e9bfdb64e54c33a22cb26e3496b96d
 */

long do_rt_sigreturn(CPUPPCState *env)

{

    struct target_rt_sigframe *rt_sf = NULL;

    target_ulong rt_sf_addr;



    rt_sf_addr = env->gpr[1] + SIGNAL_FRAMESIZE + 16;

    if (!lock_user_struct(VERIFY_READ, rt_sf, rt_sf_addr, 1))

        goto sigsegv;



    if (do_setcontext(&rt_sf->uc, env, 1))

        goto sigsegv;



    do_sigaltstack(rt_sf_addr

                   + offsetof(struct target_rt_sigframe, uc.tuc_stack),

                   0, env->gpr[1]);



    unlock_user_struct(rt_sf, rt_sf_addr, 1);

    return -TARGET_QEMU_ESIGRETURN;



sigsegv:

    unlock_user_struct(rt_sf, rt_sf_addr, 1);

    force_sig(TARGET_SIGSEGV);

    return 0;

}
