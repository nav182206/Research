/* 
 * Benchmark Sample ID : devign_9327
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5fe79386ba3cdc86fd808dde301bfc5bb7e9bded
 */

static void pc_machine_set_nvdimm(Object *obj, bool value, Error **errp)

{

    PCMachineState *pcms = PC_MACHINE(obj);



    pcms->nvdimm = value;

}
