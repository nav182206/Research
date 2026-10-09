/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_7549
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=063cac5326518abfcd4f3f0eaace3fa9b1a97424
 */

int ppc_get_compat_smt_threads(PowerPCCPU *cpu)

{

    int ret = smp_threads;

    PowerPCCPUClass *pcc = POWERPC_CPU_GET_CLASS(cpu);



    switch (cpu->cpu_version) {

    case CPU_POWERPC_LOGICAL_2_05:

        ret = 2;

        break;

    case CPU_POWERPC_LOGICAL_2_06:

        ret = 4;

        break;

    case CPU_POWERPC_LOGICAL_2_07:

        ret = 8;

        break;

    default:

        if (pcc->pcr_mask & PCR_COMPAT_2_06) {

            ret = 4;

        } else if (pcc->pcr_mask & PCR_COMPAT_2_05) {

            ret = 2;

        }

        break;

    }



    return MIN(ret, smp_threads);

}
