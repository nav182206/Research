/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6941
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a2db2a1edd06a50b8a862c654cf993368cf9f1d9
 */

static void xen_main_loop_prepare(XenIOState *state)

{

    int evtchn_fd = -1;



    if (state->xce_handle != XC_HANDLER_INITIAL_VALUE) {

        evtchn_fd = xc_evtchn_fd(state->xce_handle);

    }



    state->buffered_io_timer = timer_new_ms(QEMU_CLOCK_REALTIME, handle_buffered_io,

                                                 state);



    if (evtchn_fd != -1) {

        CPUState *cpu_state;



        DPRINTF("%s: Init cpu_by_vcpu_id\n", __func__);

        CPU_FOREACH(cpu_state) {

            DPRINTF("%s: cpu_by_vcpu_id[%d]=%p\n",

                    __func__, cpu_state->cpu_index, cpu_state);

            state->cpu_by_vcpu_id[cpu_state->cpu_index] = cpu_state;

        }

        qemu_set_fd_handler(evtchn_fd, cpu_handle_ioreq, NULL, state);

    }

}
