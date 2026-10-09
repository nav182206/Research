/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9095
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t subpage_read(void *opaque, target_phys_addr_t addr,

                             unsigned len)

{

    subpage_t *mmio = opaque;

    unsigned int idx = SUBPAGE_IDX(addr);

    MemoryRegionSection *section;

#if defined(DEBUG_SUBPAGE)

    printf("%s: subpage %p len %d addr " TARGET_FMT_plx " idx %d\n", __func__,

           mmio, len, addr, idx);

#endif



    section = &phys_sections[mmio->sub_section[idx]];

    addr += mmio->base;

    addr -= section->offset_within_address_space;

    addr += section->offset_within_region;

    return io_mem_read(section->mr, addr, len);

}
