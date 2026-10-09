/* 
 * Benchmark Sample ID : devign_5574
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e1c57ab86f3c4ea6532b51cfecf32770b45f5e7a
 */

void memory_region_init_ram(MemoryRegion *mr,

                            Object *owner,

                            const char *name,

                            uint64_t size)

{

    memory_region_init(mr, owner, name, size);

    mr->ram = true;

    mr->terminates = true;

    mr->destructor = memory_region_destructor_ram;

    mr->ram_addr = qemu_ram_alloc(size, mr);

}
