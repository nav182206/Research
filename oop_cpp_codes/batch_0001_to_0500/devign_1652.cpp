/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_1652
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b0706b716769494f321a0d2bfd9fa9893992f995
 */

static bool tlb_is_dirty_ram(CPUTLBEntry *tlbe)

{

    return (tlbe->addr_write & (TLB_INVALID_MASK|TLB_MMIO|TLB_NOTDIRTY)) == 0;

}
