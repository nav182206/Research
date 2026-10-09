/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8499
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b47d8efa9f430c332bf96ce6eede169eb48422ad
 */

static void vfio_put_device(VFIOPCIDevice *vdev)

{

    QLIST_REMOVE(vdev, next);

    vdev->vbasedev.group = NULL;

    trace_vfio_put_device(vdev->vbasedev.fd);

    close(vdev->vbasedev.fd);

    g_free(vdev->vbasedev.name);

    if (vdev->msix) {

        g_free(vdev->msix);

        vdev->msix = NULL;

    }

}
