/* 
 * Benchmark Sample ID : devign_5959
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d25228e7befac33b665cd9250292de47ae6b78b5
 */

static void spapr_machine_2_3_class_init(ObjectClass *oc, void *data)

{

    MachineClass *mc = MACHINE_CLASS(oc);



    mc->name = "pseries-2.3";

    mc->desc = "pSeries Logical Partition (PAPR compliant) v2.3";

    mc->alias = "pseries";

    mc->is_default = 1;

}
