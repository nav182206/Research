/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6452
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=52c91dac6bd891656f297dab76da51fc8bc61309
 */

void memory_region_init_alias(MemoryRegion *mr,

                              Object *owner,

                              const char *name,

                              MemoryRegion *orig,

                              hwaddr offset,

                              uint64_t size)

{

    memory_region_init(mr, owner, name, size);

    memory_region_ref(orig);

    mr->destructor = memory_region_destructor_alias;

    mr->alias = orig;

    mr->alias_offset = offset;

}
