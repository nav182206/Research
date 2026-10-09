/* 
 * Benchmark Sample ID : devign_9732
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

qemu_irq *mcf_intc_init(MemoryRegion *sysmem,

                        target_phys_addr_t base,

                        CPUM68KState *env)

{

    mcf_intc_state *s;



    s = g_malloc0(sizeof(mcf_intc_state));

    s->env = env;

    mcf_intc_reset(s);



    memory_region_init_io(&s->iomem, &mcf_intc_ops, s, "mcf", 0x100);

    memory_region_add_subregion(sysmem, base, &s->iomem);



    return qemu_allocate_irqs(mcf_intc_set_irq, s, 64);

}
