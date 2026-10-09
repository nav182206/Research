/* 
 * Benchmark Sample ID : devign_9831
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5f5a1318653c08e435cfa52f60b6a712815b659d
 */

void virtio_config_writew(VirtIODevice *vdev, uint32_t addr, uint32_t data)

{

    VirtioDeviceClass *k = VIRTIO_DEVICE_GET_CLASS(vdev);

    uint16_t val = data;



    if (addr > (vdev->config_len - sizeof(val)))

        return;



    stw_p(vdev->config + addr, val);



    if (k->set_config) {

        k->set_config(vdev, vdev->config);

    }

}
