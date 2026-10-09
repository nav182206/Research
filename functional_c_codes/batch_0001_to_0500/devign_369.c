/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_369
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4c8ae0f60e63478aea0a1741cca95474b68fb949
 */

static inline bool migration_bitmap_test_and_reset_dirty(MemoryRegion *mr,

                                                         ram_addr_t offset)

{

    bool ret;

    int nr = (mr->ram_addr + offset) >> TARGET_PAGE_BITS;



    ret = test_and_clear_bit(nr, migration_bitmap);



    if (ret) {

        migration_dirty_pages--;

    }

    return ret;

}
