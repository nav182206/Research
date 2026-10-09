/* 
 * Benchmark Sample ID : devign_6600
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c627e7526a902dd5bb1907dbbd5cf961679dfa68
 */

static void rc4030_dma_tt_write(void *opaque, hwaddr addr, uint64_t data,

                                unsigned int size)

{

    rc4030State *s = opaque;



    /* write memory */

    memcpy(memory_region_get_ram_ptr(&s->dma_tt) + addr, &data, size);



    /* update dma address space (only if frame field has been written) */

    if (addr % sizeof(dma_pagetable_entry) == 0) {

        int index = addr / sizeof(dma_pagetable_entry);

        memory_region_transaction_begin();

        rc4030_dma_as_update_one(s, index, (uint32_t)data);

        memory_region_transaction_commit();

    }

}
