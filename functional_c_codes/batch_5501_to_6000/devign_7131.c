/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7131
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3a130f4ef07f4532500473aeab43c86a3c2991c8
 */

static void memory_region_iorange_read(IORange *iorange,

                                       uint64_t offset,

                                       unsigned width,

                                       uint64_t *data)

{

    MemoryRegion *mr = container_of(iorange, MemoryRegion, iorange);



    if (mr->ops->old_portio) {

        const MemoryRegionPortio *mrp = find_portio(mr, offset, width, false);



        *data = ((uint64_t)1 << (width * 8)) - 1;

        if (mrp) {

            *data = mrp->read(mr->opaque, offset - mrp->offset);

        }

        return;

    }

    *data = mr->ops->read(mr->opaque, offset, width);

}
