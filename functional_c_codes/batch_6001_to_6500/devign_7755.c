/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7755
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=82ca891283a08cddd659b534592fe00f2159bc74
 */

static int vfio_mmap_bar(VFIOBAR *bar, MemoryRegion *mem, MemoryRegion *submem,

                         void **map, size_t size, off_t offset,

                         const char *name)

{

    int ret = 0;



    if (size && bar->flags & VFIO_REGION_INFO_FLAG_MMAP) {

        int prot = 0;



        if (bar->flags & VFIO_REGION_INFO_FLAG_READ) {

            prot |= PROT_READ;

        }



        if (bar->flags & VFIO_REGION_INFO_FLAG_WRITE) {

            prot |= PROT_WRITE;

        }



        *map = mmap(NULL, size, prot, MAP_SHARED,

                    bar->fd, bar->fd_offset + offset);

        if (*map == MAP_FAILED) {

            *map = NULL;

            ret = -errno;

            goto empty_region;

        }



        memory_region_init_ram_ptr(submem, name, size, *map);

    } else {

empty_region:

        /* Create a zero sized sub-region to make cleanup easy. */

        memory_region_init(submem, name, 0);

    }



    memory_region_add_subregion(mem, offset, submem);



    return ret;

}
