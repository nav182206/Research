/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9900
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=af103c9310b7ab56a2552965d9d1274b0024f27b
 */

static void vhost_scsi_unrealize(DeviceState *dev, Error **errp)

{

    VirtIODevice *vdev = VIRTIO_DEVICE(dev);

    VHostSCSI *s = VHOST_SCSI(dev);



    migrate_del_blocker(s->migration_blocker);

    error_free(s->migration_blocker);



    /* This will stop vhost backend. */

    vhost_scsi_set_status(vdev, 0);




    g_free(s->dev.vqs);



    virtio_scsi_common_unrealize(dev, errp);

}
