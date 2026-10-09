/* 
 * Benchmark Sample ID : devign_8080
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7ebaf7955603cc50988e0eafd5e6074320fefc70
 */

static void spapr_cpu_core_register(const SPAPRCoreInfo *info)

{

    TypeInfo type_info = {

        .parent = TYPE_SPAPR_CPU_CORE,

        .instance_size = sizeof(sPAPRCPUCore),

        .instance_init = info->initfn,

    };



    type_info.name = g_strdup_printf("%s-" TYPE_SPAPR_CPU_CORE, info->name);

    type_register(&type_info);

    g_free((void *)type_info.name);

}
