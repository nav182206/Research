/* 
 * Benchmark Sample ID : devign_3220
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ad07cd69ecaffbaa015459a46975ab32e50df805
 */

static void virtio_scsi_handle_event(VirtIODevice *vdev, VirtQueue *vq)

{

    VirtIOSCSI *s = VIRTIO_SCSI(vdev);



    if (s->ctx) {

        virtio_scsi_dataplane_start(s);

        if (!s->dataplane_fenced) {

            return;

        }

    }

    virtio_scsi_handle_event_vq(s, vq);

}
