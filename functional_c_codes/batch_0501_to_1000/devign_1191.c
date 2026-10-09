/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1191
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4482e05cbbb7e50e476f6a9500cf0b38913bd939
 */

CPUState *cpu_generic_init(const char *typename, const char *cpu_model)

{

    /* TODO: all callers of cpu_generic_init() need to be converted to

     * call cpu_parse_features() only once, before calling cpu_generic_init().

     */

    const char *cpu_type = cpu_parse_cpu_model(typename, cpu_model);



    if (cpu_type) {

        return cpu_create(cpu_type);

    }

    return NULL;

}
