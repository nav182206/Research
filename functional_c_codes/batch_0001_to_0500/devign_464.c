/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_464
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f811f97040a48358b456b46ecbc9167f0131034f
 */

static void virtio_serial_device_unrealize(DeviceState *dev, Error **errp)
{
    VirtIODevice *vdev = VIRTIO_DEVICE(dev);
    VirtIOSerial *vser = VIRTIO_SERIAL(dev);
    QLIST_REMOVE(vser, next);
    g_free(vser->ivqs);
    g_free(vser->ovqs);
    g_free(vser->ports_map);
    if (vser->post_load) {
        g_free(vser->post_load->connected);
        timer_del(vser->post_load->timer);
        timer_free(vser->post_load->timer);
        g_free(vser->post_load);
    }
    virtio_cleanup(vdev);
}
