/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7464
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t mv88w8618_pit_read(void *opaque, target_phys_addr_t offset,

                                   unsigned size)

{

    mv88w8618_pit_state *s = opaque;

    mv88w8618_timer_state *t;



    switch (offset) {

    case MP_PIT_TIMER1_VALUE ... MP_PIT_TIMER4_VALUE:

        t = &s->timer[(offset-MP_PIT_TIMER1_VALUE) >> 2];

        return ptimer_get_count(t->ptimer);



    default:

        return 0;

    }

}
