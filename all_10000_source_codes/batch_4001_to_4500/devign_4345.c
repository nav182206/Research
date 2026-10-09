/* 
 * Benchmark Sample ID : devign_4345
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cfde4bd93100c58c0bfaed76deefb144caac488f
 */

void cpu_tlb_update_dirty(CPUState *env)

{

    int i;

    for(i = 0; i < CPU_TLB_SIZE; i++)

        tlb_update_dirty(&env->tlb_table[0][i]);

    for(i = 0; i < CPU_TLB_SIZE; i++)

        tlb_update_dirty(&env->tlb_table[1][i]);

#if (NB_MMU_MODES >= 3)

    for(i = 0; i < CPU_TLB_SIZE; i++)

        tlb_update_dirty(&env->tlb_table[2][i]);

#endif

#if (NB_MMU_MODES >= 4)

    for(i = 0; i < CPU_TLB_SIZE; i++)

        tlb_update_dirty(&env->tlb_table[3][i]);

#endif

#if (NB_MMU_MODES >= 5)

    for(i = 0; i < CPU_TLB_SIZE; i++)

        tlb_update_dirty(&env->tlb_table[4][i]);

#endif

}
