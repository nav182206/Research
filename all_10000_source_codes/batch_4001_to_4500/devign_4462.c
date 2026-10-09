/* 
 * Benchmark Sample ID : devign_4462
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=30fb2ca603e8b8d0f02630ef18bc0d0637a88ffa
 */

VirtIODevice *virtio_balloon_init(DeviceState *dev)

{

    VirtIOBalloon *s;



    s = (VirtIOBalloon *)virtio_common_init("virtio-balloon",

                                            VIRTIO_ID_BALLOON,

                                            8, sizeof(VirtIOBalloon));



    s->vdev.get_config = virtio_balloon_get_config;

    s->vdev.set_config = virtio_balloon_set_config;

    s->vdev.get_features = virtio_balloon_get_features;



    s->ivq = virtio_add_queue(&s->vdev, 128, virtio_balloon_handle_output);

    s->dvq = virtio_add_queue(&s->vdev, 128, virtio_balloon_handle_output);

    s->svq = virtio_add_queue(&s->vdev, 128, virtio_balloon_receive_stats);



    reset_stats(s);

    qemu_add_balloon_handler(virtio_balloon_to_target, s);



    register_savevm(dev, "virtio-balloon", -1, 1,

                    virtio_balloon_save, virtio_balloon_load, s);



    return &s->vdev;

}
