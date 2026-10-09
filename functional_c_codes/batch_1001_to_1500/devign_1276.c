/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1276
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static void ahci_idp_write(void *opaque, target_phys_addr_t addr,

                           uint64_t val, unsigned size)

{

    AHCIState *s = opaque;



    if (addr == s->idp_offset) {

        /* index register - mask off reserved bits */

        s->idp_index = (uint32_t)val & ((AHCI_MEM_BAR_SIZE - 1) & ~3);

    } else if (addr == s->idp_offset + 4) {

        /* data register - do memory write at location selected by index */

        ahci_mem_write(opaque, s->idp_index, val, size);

    }

}
