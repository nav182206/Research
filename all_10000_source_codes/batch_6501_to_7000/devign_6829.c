/* 
 * Benchmark Sample ID : devign_6829
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3caab54d081bb3ce1b237d9628dd2b8ee7680159
 */

static void qvirtio_scsi_pci_free(QVirtIOSCSI *vs)

{

    int i;



    for (i = 0; i < vs->num_queues + 2; i++) {

        qvirtqueue_cleanup(vs->dev->bus, vs->vq[i], vs->qs->alloc);

    }

    qvirtio_pci_device_disable(container_of(vs->dev, QVirtioPCIDevice, vdev));

    g_free(vs->dev);

    qvirtio_scsi_stop(vs->qs);

    g_free(vs);

}
