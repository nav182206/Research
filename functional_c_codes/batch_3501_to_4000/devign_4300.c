/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4300
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b0f74c87a1dbd6b0c5e4de7f1c5cb40197e3fbe9
 */

static void set_next_tick(rc4030State *s)

{

    qemu_irq_lower(s->timer_irq);

    uint32_t hz;



    hz = 1000 / (s->itr + 1);



    qemu_mod_timer(s->periodic_timer, qemu_get_clock(vm_clock) + ticks_per_sec / hz);

}
