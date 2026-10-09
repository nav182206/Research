/* 
 * Benchmark Sample ID : devign_4728
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=78e8fde26c032931ca2ae13bfc7c59e38afd17ee
 */

int kvm_arch_handle_exit(CPUPPCState *env, struct kvm_run *run)

{

    int ret;



    switch (run->exit_reason) {

    case KVM_EXIT_DCR:

        if (run->dcr.is_write) {

            dprintf("handle dcr write\n");

            ret = kvmppc_handle_dcr_write(env, run->dcr.dcrn, run->dcr.data);

        } else {

            dprintf("handle dcr read\n");

            ret = kvmppc_handle_dcr_read(env, run->dcr.dcrn, &run->dcr.data);

        }

        break;

    case KVM_EXIT_HLT:

        dprintf("handle halt\n");

        ret = kvmppc_handle_halt(env);

        break;

#ifdef CONFIG_PSERIES

    case KVM_EXIT_PAPR_HCALL:

        dprintf("handle PAPR hypercall\n");

        run->papr_hcall.ret = spapr_hypercall(env, run->papr_hcall.nr,

                                              run->papr_hcall.args);

        ret = 1;

        break;

#endif

    default:

        fprintf(stderr, "KVM: unknown exit reason %d\n", run->exit_reason);

        ret = -1;

        break;

    }



    return ret;

}
