/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_6728
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2ee4aed86ff2ba38a0e1846de18a9aec38d73015
 */

static void invalidate_tlb (int idx, int use_extra)

{

    tlb_t *tlb;

    target_ulong addr;

    uint8_t ASID;



    ASID = env->CP0_EntryHi & 0xFF;



    tlb = &env->tlb[idx];

    /* The qemu TLB is flushed then the ASID changes, so no need to

       flush these entries again.  */

    if (tlb->G == 0 && tlb->ASID != ASID) {

        return;

    }



    if (use_extra && env->tlb_in_use < MIPS_TLB_MAX) {

        /* For tlbwr, we can shadow the discarded entry into

	   a new (fake) TLB entry, as long as the guest can not

	   tell that it's there.  */

        env->tlb[env->tlb_in_use] = *tlb;

        env->tlb_in_use++;

        return;

    }



    if (tlb->V0) {

        tb_invalidate_page_range(tlb->PFN[0], tlb->end - tlb->VPN);

        addr = tlb->VPN;

        while (addr < tlb->end) {

            tlb_flush_page (env, addr);

            addr += TARGET_PAGE_SIZE;

        }

    }

    if (tlb->V1) {

        tb_invalidate_page_range(tlb->PFN[1], tlb->end2 - tlb->end);

        addr = tlb->end;

        while (addr < tlb->end2) {

            tlb_flush_page (env, addr);

            addr += TARGET_PAGE_SIZE;

        }

    }

}
