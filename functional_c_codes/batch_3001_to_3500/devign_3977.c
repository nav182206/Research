/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3977
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=96b1a8bb55f1aeb72a943d1001841ff8b0687059
 */

S390CPU *cpu_s390x_init(const char *cpu_model)

{

    S390CPU *cpu;



    cpu = S390_CPU(object_new(TYPE_S390_CPU));



    object_property_set_bool(OBJECT(cpu), true, "realized", NULL);



    return cpu;

}
