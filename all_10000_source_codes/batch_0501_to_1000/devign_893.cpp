/* 
 * Benchmark Sample ID : devign_893
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6643e2f001f207bdb85646a4c48d1e13244d87c3
 */

static int kvm_mce_in_exception(CPUState *env)

{

    struct kvm_msr_entry msr_mcg_status = {

        .index = MSR_MCG_STATUS,

    };

    int r;



    r = kvm_get_msr(env, &msr_mcg_status, 1);

    if (r == -1 || r == 0) {

        return -1;

    }

    return !!(msr_mcg_status.data & MCG_STATUS_MCIP);

}
