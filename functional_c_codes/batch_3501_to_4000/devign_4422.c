/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4422
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9f939df955a4152aad69a19a77e0898631bb2c18
 */

void qemu_chr_generic_open(CharDriverState *s)

{

    if (s->open_timer == NULL) {

        s->open_timer = qemu_new_timer_ms(rt_clock,

                                          qemu_chr_fire_open_event, s);

        qemu_mod_timer(s->open_timer, qemu_get_clock_ms(rt_clock) - 1);

    }

}
