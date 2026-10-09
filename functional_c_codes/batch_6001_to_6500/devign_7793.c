/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7793
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static uint64_t ivshmem_io_read(void *opaque, target_phys_addr_t addr,

                                unsigned size)

{



    IVShmemState *s = opaque;

    uint32_t ret;



    switch (addr)

    {

        case INTRMASK:

            ret = ivshmem_IntrMask_read(s);

            break;



        case INTRSTATUS:

            ret = ivshmem_IntrStatus_read(s);

            break;



        case IVPOSITION:

            /* return my VM ID if the memory is mapped */

            if (s->shm_fd > 0) {

                ret = s->vm_id;

            } else {

                ret = -1;

            }

            break;



        default:

            IVSHMEM_DPRINTF("why are we reading " TARGET_FMT_plx "\n", addr);

            ret = 0;

    }



    return ret;

}
