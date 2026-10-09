/* 
 * Benchmark Sample ID : devign_1942
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=93b665693dd4afd32c89b0d5ee2b407b26a7a3bc
 */

static void rtc_periodic_timer(void *opaque)

{

    RTCState *s = opaque;



    rtc_timer_update(s, s->next_periodic_time);

#ifdef TARGET_I386

    if ((s->cmos_data[RTC_REG_C] & 0xc0) && rtc_td_hack) {

        s->irq_coalesced++;

        return;

    }

#endif

    if (s->cmos_data[RTC_REG_B] & REG_B_PIE) {

        s->cmos_data[RTC_REG_C] |= 0xc0;

        rtc_irq_raise(s->irq);

    }

    if (s->cmos_data[RTC_REG_B] & REG_B_SQWE) {

        /* Not square wave at all but we don't want 2048Hz interrupts!

           Must be seen as a pulse.  */

        qemu_irq_raise(s->sqw_irq);

    }

}
