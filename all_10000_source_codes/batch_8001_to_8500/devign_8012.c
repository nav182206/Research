/* 
 * Benchmark Sample ID : devign_8012
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=bd4b65ee5e5f750da709ac10c70266876e515c23
 */

int pci_device_load(PCIDevice *s, QEMUFile *f)

{

    uint32_t version_id;

    int i;



    version_id = qemu_get_be32(f);

    if (version_id > 2)

        return -EINVAL;

    qemu_get_buffer(f, s->config, 256);

    pci_update_mappings(s);



    if (version_id >= 2)

        for (i = 0; i < 4; i ++)

            s->irq_state[i] = qemu_get_be32(f);

    return 0;

}
