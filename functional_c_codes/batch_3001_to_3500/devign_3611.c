/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3611
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f9aebe2ef52ff0dcb733999f57e00a7b430303c6
 */

static int get_pci_config_device(QEMUFile *f, void *pv, size_t size)

{

    PCIDevice *s = container_of(pv, PCIDevice, config);

    uint8_t *config;

    int i;



    assert(size == pci_config_size(s));

    config = qemu_malloc(size);



    qemu_get_buffer(f, config, size);

    for (i = 0; i < size; ++i) {

        if ((config[i] ^ s->config[i]) & s->cmask[i] & ~s->wmask[i]) {

            qemu_free(config);

            return -EINVAL;

        }

    }

    memcpy(s->config, config, size);



    pci_update_mappings(s);



    qemu_free(config);

    return 0;

}
