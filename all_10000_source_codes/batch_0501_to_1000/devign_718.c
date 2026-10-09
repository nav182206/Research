/* 
 * Benchmark Sample ID : devign_718
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3356128cd13d7ec7689b7cddd3efbfbc5339a262
 */

int vfio_container_ioctl(AddressSpace *as, int32_t groupid,

                         int req, void *param)

{

    /* We allow only certain ioctls to the container */

    switch (req) {

    case VFIO_CHECK_EXTENSION:

    case VFIO_IOMMU_SPAPR_TCE_GET_INFO:

    case VFIO_EEH_PE_OP:

        break;

    default:

        /* Return an error on unknown requests */

        error_report("vfio: unsupported ioctl %X", req);

        return -1;

    }



    return vfio_container_do_ioctl(as, groupid, req, param);

}
