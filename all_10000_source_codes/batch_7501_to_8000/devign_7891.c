/* 
 * Benchmark Sample ID : devign_7891
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8d04fb55dec381bc5105cb47f29d918e579e8cbd
 */

static void tcg_handle_interrupt(CPUState *cpu, int mask)

{

    int old_mask;



    old_mask = cpu->interrupt_request;

    cpu->interrupt_request |= mask;



    /*

     * If called from iothread context, wake the target cpu in

     * case its halted.

     */

    if (!qemu_cpu_is_self(cpu)) {

        qemu_cpu_kick(cpu);

        return;

    }



    if (use_icount) {

        cpu->icount_decr.u16.high = 0xffff;

        if (!cpu->can_do_io

            && (mask & ~old_mask) != 0) {

            cpu_abort(cpu, "Raised interrupt while not in I/O function");

        }

    } else {

        cpu->tcg_exit_req = 1;

    }

}
