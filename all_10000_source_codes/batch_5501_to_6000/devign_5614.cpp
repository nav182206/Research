/* 
 * Benchmark Sample ID : devign_5614
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=66b9b43c42049bcae37668e890fedde9a72c8167
 */

static void check_watchpoint(int offset, int len, int flags)

{

    CPUState *cpu = current_cpu;

    CPUArchState *env = cpu->env_ptr;

    target_ulong pc, cs_base;

    target_ulong vaddr;

    CPUWatchpoint *wp;

    int cpu_flags;



    if (cpu->watchpoint_hit) {

        /* We re-entered the check after replacing the TB. Now raise

         * the debug interrupt so that is will trigger after the

         * current instruction. */

        cpu_interrupt(cpu, CPU_INTERRUPT_DEBUG);

        return;

    }

    vaddr = (cpu->mem_io_vaddr & TARGET_PAGE_MASK) + offset;

    QTAILQ_FOREACH(wp, &cpu->watchpoints, entry) {

        if (cpu_watchpoint_address_matches(wp, vaddr, len)

            && (wp->flags & flags)) {

            if (flags == BP_MEM_READ) {

                wp->flags |= BP_WATCHPOINT_HIT_READ;

            } else {

                wp->flags |= BP_WATCHPOINT_HIT_WRITE;

            }

            wp->hitaddr = vaddr;

            if (!cpu->watchpoint_hit) {

                cpu->watchpoint_hit = wp;

                tb_check_watchpoint(cpu);

                if (wp->flags & BP_STOP_BEFORE_ACCESS) {

                    cpu->exception_index = EXCP_DEBUG;

                    cpu_loop_exit(cpu);

                } else {

                    cpu_get_tb_cpu_state(env, &pc, &cs_base, &cpu_flags);

                    tb_gen_code(cpu, pc, cs_base, cpu_flags, 1);

                    cpu_resume_from_signal(cpu, NULL);

                }

            }

        } else {

            wp->flags &= ~BP_WATCHPOINT_HIT;

        }

    }

}
