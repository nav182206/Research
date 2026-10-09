/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1660
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fbeadf50f2f965741def823036b086bbc2999b1f
 */

static void memory_region_dispatch_write(MemoryRegion *mr,

                                         hwaddr addr,

                                         uint64_t data,

                                         unsigned size)

{

    if (!memory_region_access_valid(mr, addr, size, true)) {

        return; /* FIXME: better signalling */

    }



    adjust_endianness(mr, &data, size);



    if (!mr->ops->write) {

        mr->ops->old_mmio.write[bitops_ffsl(size)](mr->opaque, addr, data);

        return;

    }



    /* FIXME: support unaligned access */

    access_with_adjusted_size(addr, &data, size,

                              mr->ops->impl.min_access_size,

                              mr->ops->impl.max_access_size,

                              memory_region_write_accessor, mr);

}
