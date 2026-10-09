/* 
 * Benchmark Sample ID : devign_4960
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0e86c13fe2058adb8c792ebb7c51a6a7ca9d3d55
 */

static void virtio_serial_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);

    VirtioDeviceClass *vdc = VIRTIO_DEVICE_CLASS(klass);

    dc->exit = virtio_serial_device_exit;

    dc->props = virtio_serial_properties;

    set_bit(DEVICE_CATEGORY_INPUT, dc->categories);

    vdc->init = virtio_serial_device_init;

    vdc->get_features = get_features;

    vdc->get_config = get_config;

    vdc->set_config = set_config;

    vdc->set_status = set_status;

    vdc->reset = vser_reset;

}
