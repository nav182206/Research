/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8987
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a87310a62d1885b8f6d6b5b30227cbd9792d2c3c
 */

static void machine_cpu_reset(MicroBlazeCPU *cpu)

{

    CPUMBState *env = &cpu->env;



    env->pvr.regs[10] = 0x0e000000; /* virtex 6 */

    /* setup pvr to match kernel setting */

    env->pvr.regs[0] |= (0x14 << 8);

    env->pvr.regs[4] = 0xc56b8000;

    env->pvr.regs[5] = 0xc56be000;

}
