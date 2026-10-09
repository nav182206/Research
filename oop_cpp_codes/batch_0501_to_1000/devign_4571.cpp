/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_4571
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=41742767bfa8127954b6f57b39b590adcde3ac6c
 */

static void xenfv_machine_options(MachineClass *m)

{

    pc_common_machine_options(m);

    m->desc = "Xen Fully-virtualized PC";

    m->max_cpus = HVM_MAX_VCPUS;

    m->default_machine_opts = "accel=xen";

    m->hot_add_cpu = pc_hot_add_cpu;

}
