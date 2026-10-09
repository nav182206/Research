/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3013
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2ce68e4cf5be9b5176a3c3c372948d6340724d2d
 */

void vhost_dev_cleanup(struct vhost_dev *hdev)

{

    int i;

    for (i = 0; i < hdev->nvqs; ++i) {

        vhost_virtqueue_cleanup(hdev->vqs + i);

    }

    memory_listener_unregister(&hdev->memory_listener);

    if (hdev->migration_blocker) {

        migrate_del_blocker(hdev->migration_blocker);

        error_free(hdev->migration_blocker);

    }

    g_free(hdev->mem);

    g_free(hdev->mem_sections);

    hdev->vhost_ops->vhost_backend_cleanup(hdev);


}
