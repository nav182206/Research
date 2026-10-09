/* 
 * Benchmark Sample ID : devign_4277
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a83000f5e3fac30a7f213af1ba6a8f827622854d
 */

static IOMMUTLBEntry spapr_tce_translate_iommu(MemoryRegion *iommu, hwaddr addr)

{

    sPAPRTCETable *tcet = container_of(iommu, sPAPRTCETable, iommu);

    uint64_t tce;



#ifdef DEBUG_TCE

    fprintf(stderr, "spapr_tce_translate liobn=0x%" PRIx32 " addr=0x"

            DMA_ADDR_FMT "\n", tcet->liobn, addr);

#endif



    if (tcet->bypass) {

        return (IOMMUTLBEntry) {

            .target_as = &address_space_memory,

            .iova = 0,

            .translated_addr = 0,

            .addr_mask = ~(hwaddr)0,

            .perm = IOMMU_RW,

        };

    }



    /* Check if we are in bound */

    if (addr >= tcet->window_size) {

#ifdef DEBUG_TCE

        fprintf(stderr, "spapr_tce_translate out of bounds\n");

#endif

        return (IOMMUTLBEntry) { .perm = IOMMU_NONE };

    }



    tce = tcet->table[addr >> SPAPR_TCE_PAGE_SHIFT].tce;



#ifdef DEBUG_TCE

    fprintf(stderr, " ->  *paddr=0x%llx, *len=0x%llx\n",

            (tce & ~SPAPR_TCE_PAGE_MASK), SPAPR_TCE_PAGE_MASK + 1);

#endif



    return (IOMMUTLBEntry) {

        .target_as = &address_space_memory,

        .iova = addr & ~SPAPR_TCE_PAGE_MASK,

        .translated_addr = tce & ~SPAPR_TCE_PAGE_MASK,

        .addr_mask = SPAPR_TCE_PAGE_MASK,

        .perm = tce,

    };

}
