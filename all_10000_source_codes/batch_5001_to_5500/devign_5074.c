/* 
 * Benchmark Sample ID : devign_5074
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=524d18d8bd463431b120eeb5f9f3d1064a1c19e4
 */

static void s390_hot_add_cpu(const int64_t id, Error **errp)

{

    MachineState *machine = MACHINE(qdev_get_machine());



    s390x_new_cpu(machine->cpu_model, id, errp);

}
