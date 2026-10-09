/* 
 * Benchmark Sample ID : devign_1134
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b3e27c3aee8f5a96debfe0346e9c0e3a641a8516
 */

static void vfio_disable_interrupts(VFIOPCIDevice *vdev)

{

    switch (vdev->interrupt) {

    case VFIO_INT_INTx:

        vfio_disable_intx(vdev);

        break;

    case VFIO_INT_MSI:

        vfio_disable_msi(vdev);

        break;

    case VFIO_INT_MSIX:

        vfio_disable_msix(vdev);

        break;

    }

}
