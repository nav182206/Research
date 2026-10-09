/* 
 * Benchmark Sample ID : devign_3664
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e1f8c729fa890c67bb4532f22c22ace6fb0e1aaf
 */

static pxa2xx_timer_info *pxa2xx_timer_init(target_phys_addr_t base,

                qemu_irq *irqs)

{

    int i;

    int iomemtype;

    pxa2xx_timer_info *s;



    s = (pxa2xx_timer_info *) qemu_mallocz(sizeof(pxa2xx_timer_info));

    s->irq_enabled = 0;

    s->oldclock = 0;

    s->clock = 0;

    s->lastload = qemu_get_clock(vm_clock);

    s->reset3 = 0;



    for (i = 0; i < 4; i ++) {

        s->timer[i].value = 0;

        s->timer[i].irq = irqs[i];

        s->timer[i].info = s;

        s->timer[i].num = i;

        s->timer[i].level = 0;

        s->timer[i].qtimer = qemu_new_timer(vm_clock,

                        pxa2xx_timer_tick, &s->timer[i]);

    }



    iomemtype = cpu_register_io_memory(pxa2xx_timer_readfn,

                    pxa2xx_timer_writefn, s, DEVICE_NATIVE_ENDIAN);

    cpu_register_physical_memory(base, 0x00001000, iomemtype);



    register_savevm(NULL, "pxa2xx_timer", 0, 0,

                    pxa2xx_timer_save, pxa2xx_timer_load, s);



    return s;

}
