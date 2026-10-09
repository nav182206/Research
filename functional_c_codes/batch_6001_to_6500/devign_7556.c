/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7556
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8d302e76755b8157373073d7107e31b0b13f80c1
 */

void tb_check_watchpoint(CPUState *cpu)

{

    TranslationBlock *tb;



    tb = tb_find_pc(cpu->mem_io_pc);

    if (!tb) {

        cpu_abort(cpu, "check_watchpoint: could not find TB for pc=%p",

                  (void *)cpu->mem_io_pc);

    }

    cpu_restore_state_from_tb(cpu, tb, cpu->mem_io_pc);

    tb_phys_invalidate(tb, -1);

}
