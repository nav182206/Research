/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4056
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f8ed85ac992c48814d916d5df4d44f9a971c5de4
 */

static int afx_init1(SysBusDevice *dev)

{

    AFXState *s = TCX_AFX(dev);



    memory_region_init_ram(&s->mem, OBJECT(s), "sun4m.afx", 4, &error_abort);

    vmstate_register_ram_global(&s->mem);

    sysbus_init_mmio(dev, &s->mem);

    return 0;

}
