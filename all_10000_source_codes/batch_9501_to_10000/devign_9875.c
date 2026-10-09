/* 
 * Benchmark Sample ID : devign_9875
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c650c008e326f3a1e84083bc269265456057a212
 */

static int do_setcontext(struct target_ucontext *ucp, CPUPPCState *env, int sig)

{

    struct target_mcontext *mcp;

    target_ulong mcp_addr;

    sigset_t blocked;

    target_sigset_t set;



    if (copy_from_user(&set, h2g(ucp) + offsetof(struct target_ucontext, tuc_sigmask),

                       sizeof (set)))

        return 1;



#if defined(TARGET_PPC64)

    fprintf (stderr, "do_setcontext: not implemented\n");

    return 0;

#else

    if (__get_user(mcp_addr, &ucp->tuc_regs))

        return 1;



    if (!lock_user_struct(VERIFY_READ, mcp, mcp_addr, 1))

        return 1;



    target_to_host_sigset_internal(&blocked, &set);

    do_sigprocmask(SIG_SETMASK, &blocked, NULL);

    if (restore_user_regs(env, mcp, sig))

        goto sigsegv;



    unlock_user_struct(mcp, mcp_addr, 1);

    return 0;



sigsegv:

    unlock_user_struct(mcp, mcp_addr, 1);

    return 1;

#endif

}
