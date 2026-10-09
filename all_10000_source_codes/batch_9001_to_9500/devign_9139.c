/* 
 * Benchmark Sample ID : devign_9139
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=187337f8b0ec0813dd3876d1efe37d415fb81c2e
 */

qemu_irq *pl190_init(uint32_t base, qemu_irq irq, qemu_irq fiq)

{

    pl190_state *s;

    qemu_irq *qi;

    int iomemtype;



    s = (pl190_state *)qemu_mallocz(sizeof(pl190_state));

    iomemtype = cpu_register_io_memory(0, pl190_readfn,

                                       pl190_writefn, s);

    cpu_register_physical_memory(base, 0x00000fff, iomemtype);

    qi = qemu_allocate_irqs(pl190_set_irq, s, 32);

    s->base = base;

    s->irq = irq;

    s->fiq = fiq;

    pl190_reset(s);

    /* ??? Save/restore.  */

    return qi;

}
