/* 
 * Benchmark Sample ID : devign_7065
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2bfe11c8fac96db4f94abbe818fbc964a6744130
 */

static void cpu_common_realizefn(DeviceState *dev, Error **errp)
{
    CPUState *cpu = CPU(dev);
    if (dev->hotplugged) {
        cpu_synchronize_post_init(cpu);
        cpu_resume(cpu);
    }
}
