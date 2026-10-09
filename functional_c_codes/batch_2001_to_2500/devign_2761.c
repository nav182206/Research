/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2761
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c599d4d6d6e9bfdb64e54c33a22cb26e3496b96d
 */

long do_rt_sigreturn(CPUS390XState *env)

{

    rt_sigframe *frame;

    abi_ulong frame_addr = env->regs[15];

    sigset_t set;



    trace_user_do_rt_sigreturn(env, frame_addr);

    if (!lock_user_struct(VERIFY_READ, frame, frame_addr, 1)) {

        goto badframe;

    }

    target_to_host_sigset(&set, &frame->uc.tuc_sigmask);



    set_sigmask(&set); /* ~_BLOCKABLE? */



    if (restore_sigregs(env, &frame->uc.tuc_mcontext)) {

        goto badframe;

    }



    if (do_sigaltstack(frame_addr + offsetof(rt_sigframe, uc.tuc_stack), 0,

                       get_sp_from_cpustate(env)) == -EFAULT) {

        goto badframe;

    }

    unlock_user_struct(frame, frame_addr, 0);

    return -TARGET_QEMU_ESIGRETURN;



badframe:

    unlock_user_struct(frame, frame_addr, 0);

    force_sig(TARGET_SIGSEGV);

    return 0;

}
