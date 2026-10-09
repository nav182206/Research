/* 
 * Benchmark Sample ID : devign_6863
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e83980455c8c7eb066405de512be7c4bace3ac4d
 */

static void virtio_ccw_device_plugged(DeviceState *d)

{

    VirtioCcwDevice *dev = VIRTIO_CCW_DEVICE(d);

    SubchDev *sch = dev->sch;



    sch->id.cu_model = virtio_bus_get_vdev_id(&dev->bus);



    css_generate_sch_crws(sch->cssid, sch->ssid, sch->schid,

                          d->hotplugged, 1);

}
