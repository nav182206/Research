/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_8395
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5f5a1318653c08e435cfa52f60b6a712815b659d
 */

uint32_t virtio_config_readb(VirtIODevice *vdev, uint32_t addr)

{

    VirtioDeviceClass *k = VIRTIO_DEVICE_GET_CLASS(vdev);

    uint8_t val;



    k->get_config(vdev, vdev->config);



    if (addr > (vdev->config_len - sizeof(val)))

        return (uint32_t)-1;



    val = ldub_p(vdev->config + addr);

    return val;

}
