/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1183
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ce5b1bbf624b977a55ff7f85bb3871682d03baff
 */

static void mips_cpu_initfn(Object *obj)

{

    CPUState *cs = CPU(obj);

    MIPSCPU *cpu = MIPS_CPU(obj);

    CPUMIPSState *env = &cpu->env;



    cs->env_ptr = env;

    cpu_exec_init(cs, &error_abort);



    if (tcg_enabled()) {

        mips_tcg_init();

    }

}
