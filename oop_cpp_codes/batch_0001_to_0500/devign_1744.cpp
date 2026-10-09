/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_1744
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=56c4bfb3f07f3107894c00281276aea4f5e8834d
 */

void qemu_get_guest_memory_mapping(MemoryMappingList *list, Error **errp)

{

    CPUState *cpu, *first_paging_enabled_cpu;

    RAMBlock *block;

    ram_addr_t offset, length;



    first_paging_enabled_cpu = find_paging_enabled_cpu(first_cpu);

    if (first_paging_enabled_cpu) {

        for (cpu = first_paging_enabled_cpu; cpu != NULL; cpu = cpu->next_cpu) {

            Error *err = NULL;

            cpu_get_memory_mapping(cpu, list, &err);

            if (err) {

                error_propagate(errp, err);

                return;

            }

        }

        return;

    }



    /*

     * If the guest doesn't use paging, the virtual address is equal to physical

     * address.

     */

    QTAILQ_FOREACH(block, &ram_list.blocks, next) {

        offset = block->offset;

        length = block->length;

        create_new_memory_mapping(list, offset, offset, length);

    }

}
