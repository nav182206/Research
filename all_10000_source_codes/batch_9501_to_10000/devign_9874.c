/* 
 * Benchmark Sample ID : devign_9874
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e389be1673052b538534643165111725a79e5afd
 */

static uint32_t get_level1_table_address(CPUARMState *env, uint32_t address)

{

    uint32_t table;



    if (address & env->cp15.c2_mask)

        table = env->cp15.ttbr1_el1 & 0xffffc000;

    else

        table = env->cp15.ttbr0_el1 & env->cp15.c2_base_mask;



    table |= (address >> 18) & 0x3ffc;

    return table;

}
