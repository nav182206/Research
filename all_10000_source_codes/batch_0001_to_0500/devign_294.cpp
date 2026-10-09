/* 
 * Benchmark Sample ID : devign_294
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=14a10fc39923b3af07c8c46d22cb20843bee3a72
 */

static void mips_cpu_realizefn(DeviceState *dev, Error **errp)

{

    MIPSCPU *cpu = MIPS_CPU(dev);

    MIPSCPUClass *mcc = MIPS_CPU_GET_CLASS(dev);



    cpu_reset(CPU(cpu));



    mcc->parent_realize(dev, errp);

}
