/* 
 * Benchmark Sample ID : devign_2439
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3c0c47e3464f3c54bd3f1cc6d4da2cbf7465e295
 */

static void spapr_machine_2_6_class_options(MachineClass *mc)

{

    sPAPRMachineClass *smc = SPAPR_MACHINE_CLASS(mc);



    spapr_machine_2_7_class_options(mc);

    smc->dr_cpu_enabled = false;

    SET_MACHINE_COMPAT(mc, SPAPR_COMPAT_2_6);

}
