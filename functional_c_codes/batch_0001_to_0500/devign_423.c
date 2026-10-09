/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_423
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a52c757c9f98311c3ba22744d609caa767b899e1
 */

get_sigframe(struct emulated_sigaction *ka, CPUX86State *env, size_t frame_size)

{

	unsigned long esp;



	/* Default to using normal stack */

	esp = env->regs[R_ESP];

#if 0

	/* This is the X/Open sanctioned signal stack switching.  */

	if (ka->sa.sa_flags & SA_ONSTACK) {

		if (sas_ss_flags(esp) == 0)

			esp = current->sas_ss_sp + current->sas_ss_size;

	}



	/* This is the legacy signal stack switching. */

	else if ((regs->xss & 0xffff) != __USER_DS &&

		 !(ka->sa.sa_flags & SA_RESTORER) &&

		 ka->sa.sa_restorer) {

		esp = (unsigned long) ka->sa.sa_restorer;

	}

#endif

	return (void *)((esp - frame_size) & -8ul);

}
