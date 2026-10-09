/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8531
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=05fcfada5e45b900c32ca6bccf0ce52cb5422509
 */

static int get_pci_config_device(QEMUFile *f, void *pv, size_t size)

{

    PCIDevice *s = container_of(pv, PCIDevice, config);

    uint8_t config[size];

    int i;



    qemu_get_buffer(f, config, size);

    for (i = 0; i < size; ++i)

        if ((config[i] ^ s->config[i]) & s->cmask[i] & ~s->wmask[i])

            return -EINVAL;

    memcpy(s->config, config, size);



    pci_update_mappings(s);



    return 0;

}
