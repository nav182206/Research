/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_1439
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=82a3d1f81f8e401c6c34cba541970197aba2bb9a
 */

AlphaCPU *cpu_alpha_init(const char *cpu_model)

{

    AlphaCPU *cpu;

    ObjectClass *cpu_class;



    cpu_class = alpha_cpu_class_by_name(cpu_model);

    if (cpu_class == NULL) {

        /* Default to ev67; no reason not to emulate insns by default.  */

        cpu_class = object_class_by_name(TYPE("ev67"));

    }

    cpu = ALPHA_CPU(object_new(object_class_get_name(cpu_class)));



    object_property_set_bool(OBJECT(cpu), true, "realized", NULL);



    return cpu;

}
