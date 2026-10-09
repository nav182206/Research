/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3441
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=dcc6ceffc066745777960a1f0d32f3a555924f65
 */

static void virtio_balloon_set_config(VirtIODevice *vdev,

                                      const uint8_t *config_data)

{

    VirtIOBalloon *dev = VIRTIO_BALLOON(vdev);

    struct virtio_balloon_config config;

    uint32_t oldactual = dev->actual;

    memcpy(&config, config_data, 8);

    dev->actual = le32_to_cpu(config.actual);

    if (dev->actual != oldactual) {

        qemu_balloon_changed(ram_size -

                             (dev->actual << VIRTIO_BALLOON_PFN_SHIFT));

    }

}
