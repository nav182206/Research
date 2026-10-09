/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9605
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d1048bef9df0aacde9a54bf9b5b97a6e10950d8c
 */

static bool pc_machine_get_vmport(Object *obj, Error **errp)

{

    PCMachineState *pcms = PC_MACHINE(obj);



    return pcms->vmport;

}
