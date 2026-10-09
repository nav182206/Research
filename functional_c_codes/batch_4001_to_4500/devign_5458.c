/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5458
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7093645a843e5da1a750bc451dd8c9107d595c61
 */

static int spapr_cpu_core_realize_child(Object *child, void *opaque)

{

    Error **errp = opaque, *local_err = NULL;

    sPAPRMachineState *spapr = SPAPR_MACHINE(qdev_get_machine());

    CPUState *cs = CPU(child);

    PowerPCCPU *cpu = POWERPC_CPU(cs);



    object_property_set_bool(child, true, "realized", &local_err);

    if (local_err) {

        error_propagate(errp, local_err);

        return 1;

    }



    spapr_cpu_init(spapr, cpu, &local_err);

    if (local_err) {

        error_propagate(errp, local_err);

        return 1;

    }

    return 0;

}
