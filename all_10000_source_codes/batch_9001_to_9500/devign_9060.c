/* 
 * Benchmark Sample ID : devign_9060
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=73534f2f682f2957fabb25e3890481098cc5dcee
 */

void pci_device_save(PCIDevice *s, QEMUFile *f)

{

    int i;



    qemu_put_be32(f, s->version_id); /* PCI device version */

    qemu_put_buffer(f, s->config, 256);

    for (i = 0; i < 4; i++)

        qemu_put_be32(f, s->irq_state[i]);

}
