/* 
 * Benchmark Sample ID : devign_2031
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ee76a09fc72cfbfab2bb5529320ef7e460adffd8
 */

static sPAPRCapabilities default_caps_with_cpu(sPAPRMachineState *spapr,

                                               CPUState *cs)

{

    sPAPRMachineClass *smc = SPAPR_MACHINE_GET_CLASS(spapr);

    sPAPRCapabilities caps;



    caps = smc->default_caps;



    /* TODO: clamp according to cpu model */



    return caps;

}
