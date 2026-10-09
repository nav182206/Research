/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_4615
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=dc54e2525389e903cee2b847cf761b5d857f75cb
 */

void kvm_remove_all_breakpoints(CPUState *cpu)

{

    struct kvm_sw_breakpoint *bp, *next;

    KVMState *s = cpu->kvm_state;



    QTAILQ_FOREACH_SAFE(bp, &s->kvm_sw_breakpoints, entry, next) {

        if (kvm_arch_remove_sw_breakpoint(cpu, bp) != 0) {

            /* Try harder to find a CPU that currently sees the breakpoint. */

            CPU_FOREACH(cpu) {

                if (kvm_arch_remove_sw_breakpoint(cpu, bp) == 0) {

                    break;

                }

            }

        }

        QTAILQ_REMOVE(&s->kvm_sw_breakpoints, bp, entry);

        g_free(bp);

    }

    kvm_arch_remove_all_hw_breakpoints();



    CPU_FOREACH(cpu) {

        kvm_update_guest_debug(cpu, 0);

    }

}
