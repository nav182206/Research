/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7079
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d861b05ea30e6ac177de9b679da96194ebe21afc
 */

void smc91c111_init(NICInfo *nd, uint32_t base, void *pic, int irq)

{

    smc91c111_state *s;

    int iomemtype;



    s = (smc91c111_state *)qemu_mallocz(sizeof(smc91c111_state));

    iomemtype = cpu_register_io_memory(0, smc91c111_readfn,

                                       smc91c111_writefn, s);

    cpu_register_physical_memory(base, 16, iomemtype);

    s->base = base;

    s->pic = pic;

    s->irq = irq;

    memcpy(s->macaddr, nd->macaddr, 6);



    smc91c111_reset(s);



    s->vc = qemu_new_vlan_client(nd->vlan, smc91c111_receive, s);

    /* ??? Save/restore.  */

}
