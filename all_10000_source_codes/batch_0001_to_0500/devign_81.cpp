/* 
 * Benchmark Sample ID : devign_81
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=95129d6fc9ead97155627a4ca0cfd37282883658
 */

void virtio_queue_set_align(VirtIODevice *vdev, int n, int align)

{

    BusState *qbus = qdev_get_parent_bus(DEVICE(vdev));

    VirtioBusClass *k = VIRTIO_BUS_GET_CLASS(qbus);



    /* virtio-1 compliant devices cannot change the alignment */

    if (virtio_has_feature(vdev, VIRTIO_F_VERSION_1)) {

        error_report("tried to modify queue alignment for virtio-1 device");

        return;

    }

    /* Check that the transport told us it was going to do this

     * (so a buggy transport will immediately assert rather than

     * silently failing to migrate this state)

     */

    assert(k->has_variable_vring_alignment);



    vdev->vq[n].vring.align = align;

    virtio_queue_update_rings(vdev, n);

}
