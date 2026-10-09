/* 
 * Benchmark Sample ID : devign_577
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=aa90fec7ad128039617d31a5fd5ced8b0488f71b
 */

static int kvm_get_dirty_pages_log_range(MemoryRegionSection *section,

                                         unsigned long *bitmap)

{

    unsigned int i, j;

    unsigned long page_number, addr, addr1, c;

    unsigned int len = ((section->size / TARGET_PAGE_SIZE) + HOST_LONG_BITS - 1) / HOST_LONG_BITS;



    /*

     * bitmap-traveling is faster than memory-traveling (for addr...)

     * especially when most of the memory is not dirty.

     */

    for (i = 0; i < len; i++) {

        if (bitmap[i] != 0) {

            c = leul_to_cpu(bitmap[i]);

            do {

                j = ffsl(c) - 1;

                c &= ~(1ul << j);

                page_number = i * HOST_LONG_BITS + j;

                addr1 = page_number * TARGET_PAGE_SIZE;

                addr = section->offset_within_region + addr1;

                memory_region_set_dirty(section->mr, addr);

            } while (c != 0);

        }

    }

    return 0;

}
