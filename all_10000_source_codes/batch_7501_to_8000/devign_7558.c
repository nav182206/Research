/* 
 * Benchmark Sample ID : devign_7558
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4a1418e07bdcfaa3177739e04707ecaec75d89e1
 */

ram_addr_t qemu_ram_addr_from_host(void *ptr)

{

    RAMBlock *prev;

    RAMBlock **prevp;

    RAMBlock *block;

    uint8_t *host = ptr;



#ifdef CONFIG_KQEMU

    if (kqemu_phys_ram_base) {

        return host - kqemu_phys_ram_base;

    }

#endif



    prev = NULL;

    prevp = &ram_blocks;

    block = ram_blocks;

    while (block && (block->host > host

                     || block->host + block->length <= host)) {

        if (prev)

          prevp = &prev->next;

        prev = block;

        block = block->next;

    }

    if (!block) {

        fprintf(stderr, "Bad ram pointer %p\n", ptr);

        abort();

    }

    return block->offset + (host - block->host);

}
