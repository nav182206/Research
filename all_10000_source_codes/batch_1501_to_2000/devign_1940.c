/* 
 * Benchmark Sample ID : devign_1940
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=71407786054cad26de7ef66718b2a57a4bcb49b5
 */

static bool virtio_scsi_data_plane_handle_ctrl(VirtIODevice *vdev,

                                               VirtQueue *vq)

{

    VirtIOSCSI *s = VIRTIO_SCSI(vdev);



    assert(s->ctx && s->dataplane_started);

    return virtio_scsi_handle_ctrl_vq(s, vq);

}
