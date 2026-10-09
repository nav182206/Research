/* 
 * Benchmark Sample ID : devign_4668
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9d2179d6f960aef1b8aab4d014fd8385f0a187e5
 */

void ppc_set_compat(PowerPCCPU *cpu, uint32_t compat_pvr, Error **errp)

{

    const CompatInfo *compat = compat_by_pvr(compat_pvr);

    CPUPPCState *env = &cpu->env;

    PowerPCCPUClass *pcc = POWERPC_CPU_GET_CLASS(cpu);

    uint64_t pcr;



    if (!compat_pvr) {

        pcr = 0;

    } else if (!compat) {

        error_setg(errp, "Unknown compatibility PVR 0x%08"PRIx32, compat_pvr);






    } else {

        pcr = compat->pcr;

    }



    cpu->compat_pvr = compat_pvr;

    env->spr[SPR_PCR] = pcr & pcc->pcr_mask;



    if (kvm_enabled()) {

        int ret = kvmppc_set_compat(cpu, cpu->compat_pvr);

        if (ret < 0) {

            error_setg_errno(errp, -ret,

                             "Unable to set CPU compatibility mode in KVM");

        }

    }

}
