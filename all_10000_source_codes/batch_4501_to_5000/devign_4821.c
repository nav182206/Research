/* 
 * Benchmark Sample ID : devign_4821
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=cc05c43ad942165ecc6ffd39e41991bee43af044
 */

static void access_with_adjusted_size(hwaddr addr,

                                      uint64_t *value,

                                      unsigned size,

                                      unsigned access_size_min,

                                      unsigned access_size_max,

                                      void (*access)(MemoryRegion *mr,

                                                     hwaddr addr,

                                                     uint64_t *value,

                                                     unsigned size,

                                                     unsigned shift,

                                                     uint64_t mask),

                                      MemoryRegion *mr)

{

    uint64_t access_mask;

    unsigned access_size;

    unsigned i;



    if (!access_size_min) {

        access_size_min = 1;

    }

    if (!access_size_max) {

        access_size_max = 4;

    }



    /* FIXME: support unaligned access? */

    access_size = MAX(MIN(size, access_size_max), access_size_min);

    access_mask = -1ULL >> (64 - access_size * 8);

    if (memory_region_big_endian(mr)) {

        for (i = 0; i < size; i += access_size) {

            access(mr, addr + i, value, access_size,

                   (size - access_size - i) * 8, access_mask);

        }

    } else {

        for (i = 0; i < size; i += access_size) {

            access(mr, addr + i, value, access_size, i * 8, access_mask);

        }

    }

}
