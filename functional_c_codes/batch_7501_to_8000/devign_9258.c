/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9258
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=81bad50ec40311797c38a7691844c7d2df9b3823
 */

target_ulong helper_evpe(CPUMIPSState *env)

{

    CPUMIPSState *other_cpu = first_cpu;

    target_ulong prev = env->mvp->CP0_MVPControl;



    do {

        if (other_cpu != env

           /* If the VPE is WFI, don't disturb its sleep.  */

           && !mips_vpe_is_wfi(other_cpu)) {

            /* Enable the VPE.  */

            other_cpu->mvp->CP0_MVPControl |= (1 << CP0MVPCo_EVP);

            mips_vpe_wake(other_cpu); /* And wake it up.  */

        }

        other_cpu = other_cpu->next_cpu;

    } while (other_cpu);

    return prev;

}
