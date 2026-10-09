/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5526
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=aea14095ea91f792ee43ee52fe6032cd8cdd7190
 */

void mips_cpu_do_unaligned_access(CPUState *cs, vaddr addr,

                                  int is_write, int is_user, uintptr_t retaddr)

{

    MIPSCPU *cpu = MIPS_CPU(cs);

    CPUMIPSState *env = &cpu->env;



    env->CP0_BadVAddr = addr;

    do_raise_exception(env, (is_write == 1) ? EXCP_AdES : EXCP_AdEL, retaddr);

}
