/* 
 * Benchmark Sample ID : devign_2884
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a8f2e5c8fffbaf7fbd4f0efc8efbeebade78008f
 */

static void virtio_scsi_handle_cmd(VirtIODevice *vdev, VirtQueue *vq)

{

    /* use non-QOM casts in the data path */

    VirtIOSCSI *s = (VirtIOSCSI *)vdev;

    VirtIOSCSIReq *req, *next;

    QTAILQ_HEAD(, VirtIOSCSIReq) reqs = QTAILQ_HEAD_INITIALIZER(reqs);



    if (s->ctx && !s->dataplane_started) {

        virtio_scsi_dataplane_start(s);

        return;

    }

    while ((req = virtio_scsi_pop_req(s, vq))) {

        if (virtio_scsi_handle_cmd_req_prepare(s, req)) {

            QTAILQ_INSERT_TAIL(&reqs, req, next);

        }

    }



    QTAILQ_FOREACH_SAFE(req, &reqs, next, next) {

        virtio_scsi_handle_cmd_req_submit(s, req);

    }

}
