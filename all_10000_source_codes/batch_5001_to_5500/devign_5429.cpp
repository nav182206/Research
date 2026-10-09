/* 
 * Benchmark Sample ID : devign_5429
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=988578886e0b9af507a7ef111f549c5dd47d93f3
 */

static inline void tlb_protect_code1(CPUTLBEntry *tlb_entry, uint32_t addr)

{

    if (addr == (tlb_entry->address & 

                 (TARGET_PAGE_MASK | TLB_INVALID_MASK)) &&

        (tlb_entry->address & ~TARGET_PAGE_MASK) != IO_MEM_CODE) {

        tlb_entry->address |= IO_MEM_CODE;

        tlb_entry->addend -= (unsigned long)phys_ram_base;

    }

}
