/* 
 * Benchmark Sample ID : devign_5928
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6886b98036a8f8f5bce8b10756ce080084cef11b
 */

static void cpu_exit_tb_from_sighandler(CPUState *cpu, void *puc)

{

#ifdef __linux__

    struct ucontext *uc = puc;

#elif defined(__OpenBSD__)

    struct sigcontext *uc = puc;

#endif



    /* XXX: use siglongjmp ? */

#ifdef __linux__

#ifdef __ia64

    sigprocmask(SIG_SETMASK, (sigset_t *)&uc->uc_sigmask, NULL);

#else

    sigprocmask(SIG_SETMASK, &uc->uc_sigmask, NULL);

#endif

#elif defined(__OpenBSD__)

    sigprocmask(SIG_SETMASK, &uc->sc_mask, NULL);

#endif



    cpu_resume_from_signal(cpu, NULL);

}
