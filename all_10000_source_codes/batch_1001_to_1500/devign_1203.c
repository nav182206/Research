/* 
 * Benchmark Sample ID : devign_1203
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b47d8efa9f430c332bf96ce6eede169eb48422ad
 */

static int vfio_pci_hot_reset_multi(VFIOPCIDevice *vdev)

{

    return vfio_pci_hot_reset(vdev, false);

}
