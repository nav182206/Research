/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_9222
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=14a10fc39923b3af07c8c46d22cb20843bee3a72
 */

static void xtensa_cpu_realizefn(DeviceState *dev, Error **errp)
{
    CPUState *cs = CPU(dev);
    XtensaCPUClass *xcc = XTENSA_CPU_GET_CLASS(dev);
    cs->gdb_num_regs = xcc->config->gdb_regmap.num_regs;
    xcc->parent_realize(dev, errp);
}
