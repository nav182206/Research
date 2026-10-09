/* 
 * Benchmark Sample ID : devign_583
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8d04fb55dec381bc5105cb47f29d918e579e8cbd
 */

static void check_watchpoint(int offset, int len, MemTxAttrs attrs, int flags)

{

    CPUState *cpu = current_cpu;

    CPUClass *cc = CPU_GET_CLASS(cpu);

    CPUArchState *env = cpu->env_ptr;

    target_ulong pc, cs_base;

    target_ulong vaddr;

    CPUWatchpoint *wp;

    uint32_t cpu_flags;



    if (cpu->watchpoint_hit) {

        /* We re-entered the check after replacing the TB. Now raise

         * the debug interrupt so that is will trigger after the

         * current instruction. */

        cpu_interrupt(cpu, CPU_INTERRUPT_DEBUG);

        return;

    }

    vaddr = (cpu->mem_io_vaddr & TARGET_PAGE_MASK) + offset;

    vaddr = cc->adjust_watchpoint_address(cpu, vaddr, len);

    QTAILQ_FOREACH(wp, &cpu->watchpoints, entry) {

        if (cpu_watchpoint_address_matches(wp, vaddr, len)

            && (wp->flags & flags)) {

            if (flags == BP_MEM_READ) {

                wp->flags |= BP_WATCHPOINT_HIT_READ;

            } else {

                wp->flags |= BP_WATCHPOINT_HIT_WRITE;

            }

            wp->hitaddr = vaddr;

            wp->hitattrs = attrs;

            if (!cpu->watchpoint_hit) {

                if (wp->flags & BP_CPU &&

                    !cc->debug_check_watchpoint(cpu, wp)) {

                    wp->flags &= ~BP_WATCHPOINT_HIT;

                    continue;

                }

                cpu->watchpoint_hit = wp;



                /* The tb_lock will be reset when cpu_loop_exit or

                 * cpu_loop_exit_noexc longjmp back into the cpu_exec

                 * main loop.

                 */

                tb_lock();

                tb_check_watchpoint(cpu);

                if (wp->flags & BP_STOP_BEFORE_ACCESS) {

                    cpu->exception_index = EXCP_DEBUG;

                    cpu_loop_exit(cpu);

                } else {

                    cpu_get_tb_cpu_state(env, &pc, &cs_base, &cpu_flags);

                    tb_gen_code(cpu, pc, cs_base, cpu_flags, 1);

                    cpu_loop_exit_noexc(cpu);

                }

            }

        } else {

            wp->flags &= ~BP_WATCHPOINT_HIT;

        }

    }

}
