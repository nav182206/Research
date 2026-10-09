/* 
 * Benchmark Sample ID : devign_2920
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e12ce78d4aa05ccf80d6a843a9227042647db39d
 */

void gen_pc_load(CPUState *env, TranslationBlock *tb,

                unsigned long searched_pc, int pc_pos, void *puc)

{

    env->regs[15] = gen_opc_pc[pc_pos];


}
