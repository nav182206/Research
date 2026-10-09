/* 
 * Benchmark Sample ID : devign_129
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f8ed85ac992c48814d916d5df4d44f9a971c5de4
 */

static void cg3_initfn(Object *obj)

{

    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);

    CG3State *s = CG3(obj);



    memory_region_init_ram(&s->rom, NULL, "cg3.prom", FCODE_MAX_ROM_SIZE,

                           &error_abort);

    memory_region_set_readonly(&s->rom, true);

    sysbus_init_mmio(sbd, &s->rom);



    memory_region_init_io(&s->reg, NULL, &cg3_reg_ops, s, "cg3.reg",

                          CG3_REG_SIZE);

    sysbus_init_mmio(sbd, &s->reg);

}
