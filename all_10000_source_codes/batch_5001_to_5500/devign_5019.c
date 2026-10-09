/* 
 * Benchmark Sample ID : devign_5019
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b47d8efa9f430c332bf96ce6eede169eb48422ad
 */

static void vfio_pci_reset_handler(void *opaque)

{

    VFIOGroup *group;

    VFIOPCIDevice *vdev;



    QLIST_FOREACH(group, &group_list, next) {

        QLIST_FOREACH(vdev, &group->device_list, next) {

            if (!vdev->reset_works || (!vdev->has_flr && vdev->has_pm_reset)) {

                vdev->needs_reset = true;

            }

        }

    }



    QLIST_FOREACH(group, &group_list, next) {

        QLIST_FOREACH(vdev, &group->device_list, next) {

            if (vdev->needs_reset) {

                vfio_pci_hot_reset_multi(vdev);

            }

        }

    }

}
