/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3623
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b40acf99bef69fa8ab0f9092ff162fde945eec12
 */

static const MemoryRegionPortio *find_portio(MemoryRegion *mr, uint64_t offset,

                                             unsigned width, bool write)

{

    const MemoryRegionPortio *mrp;



    for (mrp = mr->ops->old_portio; mrp->size; ++mrp) {

        if (offset >= mrp->offset && offset < mrp->offset + mrp->len

            && width == mrp->size

            && (write ? (bool)mrp->write : (bool)mrp->read)) {

            return mrp;

        }

    }

    return NULL;

}
