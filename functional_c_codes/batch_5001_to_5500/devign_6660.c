/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6660
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=83e6813a93e38976391b8c382c3375e3e188df3e
 */

static void aarch64_cpu_register(const ARMCPUInfo *info)

{

    TypeInfo type_info = {

        .parent = TYPE_AARCH64_CPU,

        .instance_size = sizeof(ARMCPU),

        .instance_init = info->initfn,

        .class_size = sizeof(ARMCPUClass),

        .class_init = info->class_init,

    };



    /* TODO: drop when we support more CPUs - all entries will have name set */

    if (!info->name) {

        return;

    }



    type_info.name = g_strdup_printf("%s-" TYPE_ARM_CPU, info->name);

    type_register(&type_info);

    g_free((void *)type_info.name);

}
