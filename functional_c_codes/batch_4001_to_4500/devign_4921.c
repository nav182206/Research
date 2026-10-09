/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4921
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=27bb0b2d6f80f058bdb6fcc8fcdfa69b0c8a6d71
 */

static void hpet_timer(void *opaque)

{

    HPETTimer *t = (HPETTimer*)opaque;

    uint64_t diff;



    uint64_t period = t->period;

    uint64_t cur_tick = hpet_get_ticks();



    if (timer_is_periodic(t) && period != 0) {

        if (t->config & HPET_TN_32BIT) {

            while (hpet_time_after(cur_tick, t->cmp))

                t->cmp = (uint32_t)(t->cmp + t->period);

        } else

            while (hpet_time_after64(cur_tick, t->cmp))

                t->cmp += period;



        diff = hpet_calculate_diff(t, cur_tick);

        qemu_mod_timer(t->qemu_timer, qemu_get_clock(vm_clock)

                       + (int64_t)ticks_to_ns(diff));

    } else if (t->config & HPET_TN_32BIT && !timer_is_periodic(t)) {

        if (t->wrap_flag) {

            diff = hpet_calculate_diff(t, cur_tick);

            qemu_mod_timer(t->qemu_timer, qemu_get_clock(vm_clock)

                           + (int64_t)ticks_to_ns(diff));

            t->wrap_flag = 0;

        }

    }

    update_irq(t);

}
