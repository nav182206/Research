/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9926
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c169998802505c244b8bcad562633f29de7d74a4
 */

void hpet_init(qemu_irq *irq) {

    int i, iomemtype;

    HPETState *s;



    dprintf ("hpet_init\n");



    s = qemu_mallocz(sizeof(HPETState));

    hpet_statep = s;

    s->irqs = irq;

    for (i=0; i<HPET_NUM_TIMERS; i++) {

        HPETTimer *timer = &s->timer[i];

        timer->qemu_timer = qemu_new_timer(vm_clock, hpet_timer, timer);

    }

    hpet_reset(s);

    vmstate_register(-1, &vmstate_hpet, s);

    qemu_register_reset(hpet_reset, s);

    /* HPET Area */

    iomemtype = cpu_register_io_memory(hpet_ram_read,

                                       hpet_ram_write, s);

    cpu_register_physical_memory(HPET_BASE, 0x400, iomemtype);

}
