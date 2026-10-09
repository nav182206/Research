/* 
 * Benchmark Sample ID : devign_8303
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4ffd16fc2900219c8ec8bb288b6fa3dfcae295a7
 */

static int64_t qemu_next_alarm_deadline(void)

{

    int64_t delta;

    int64_t rtdelta;



    if (!use_icount && vm_clock->active_timers) {

        delta = vm_clock->active_timers->expire_time -

                     qemu_get_clock_ns(vm_clock);

    } else {

        delta = INT32_MAX;

    }

    if (host_clock->active_timers) {

        int64_t hdelta = host_clock->active_timers->expire_time -

                 qemu_get_clock_ns(host_clock);

        if (hdelta < delta) {

            delta = hdelta;

        }

    }

    if (rt_clock->active_timers) {

        rtdelta = (rt_clock->active_timers->expire_time -

                 qemu_get_clock_ns(rt_clock));

        if (rtdelta < delta) {

            delta = rtdelta;

        }

    }



    return delta;

}
