/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_3812
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=14a10fc39923b3af07c8c46d22cb20843bee3a72
 */

static void s390_cpu_realizefn(DeviceState *dev, Error **errp)

{

    S390CPU *cpu = S390_CPU(dev);

    S390CPUClass *scc = S390_CPU_GET_CLASS(dev);



    cpu_reset(CPU(cpu));



    scc->parent_realize(dev, errp);

}
