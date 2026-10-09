/* 
 * Benchmark Sample ID : devign_456
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2374e73edafff0586cbfb67c333c5a7588f81fd5
 */

uint64_t helper_st_virt_to_phys (uint64_t virtaddr)

{

    uint64_t tlb_addr, physaddr;

    int index, mmu_idx;

    void *retaddr;



    mmu_idx = cpu_mmu_index(env);

    index = (virtaddr >> TARGET_PAGE_BITS) & (CPU_TLB_SIZE - 1);

 redo:

    tlb_addr = env->tlb_table[mmu_idx][index].addr_write;

    if ((virtaddr & TARGET_PAGE_MASK) ==

        (tlb_addr & (TARGET_PAGE_MASK | TLB_INVALID_MASK))) {

        physaddr = virtaddr + env->tlb_table[mmu_idx][index].addend;

    } else {

        /* the page is not in the TLB : fill it */

        retaddr = GETPC();

        tlb_fill(virtaddr, 1, mmu_idx, retaddr);

        goto redo;

    }

    return physaddr;

}
