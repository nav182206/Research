/* 
 * Benchmark Sample ID : devign_651
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c611c76417f52b335ecaab01c61743e3b705eb7c
 */

void virtio_cleanup(VirtIODevice *vdev)

{

    qemu_del_vm_change_state_handler(vdev->vmstate);

    g_free(vdev->config);

    g_free(vdev->vq);

    g_free(vdev->vector_queues);

}
