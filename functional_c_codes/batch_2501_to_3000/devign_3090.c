/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3090
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7ebaf7955603cc50988e0eafd5e6074320fefc70
 */

static void spapr_cpu_core_register_types(void)

{

    const SPAPRCoreInfo *info = spapr_cores;



    type_register_static(&spapr_cpu_core_type_info);

    while (info->name) {

        spapr_cpu_core_register(info);

        info++;

    }

}
