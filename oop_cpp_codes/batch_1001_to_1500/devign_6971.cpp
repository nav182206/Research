/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_6971
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=35c2c8dc8c0899882a8e0d349d93bd657772f1e7
 */

void x86_cpudef_setup(void)

{

    int i, j;

    static const char *model_with_versions[] = { "qemu32", "qemu64", "athlon" };



    for (i = 0; i < ARRAY_SIZE(builtin_x86_defs); ++i) {

        X86CPUDefinition *def = &builtin_x86_defs[i];



        /* Look for specific "cpudef" models that */

        /* have the QEMU version in .model_id */

        for (j = 0; j < ARRAY_SIZE(model_with_versions); j++) {

            if (strcmp(model_with_versions[j], def->name) == 0) {

                pstrcpy(def->model_id, sizeof(def->model_id),

                        "QEMU Virtual CPU version ");

                pstrcat(def->model_id, sizeof(def->model_id),

                        qemu_get_version());

                break;

            }

        }

    }

}
