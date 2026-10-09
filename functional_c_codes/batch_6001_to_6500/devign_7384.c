/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7384
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1760048a5d21bacf0e4838da2f61b2d8db7d2866
 */

static QPCIDevice *get_device(void)

{

    QPCIDevice *dev;

    QPCIBus *pcibus;



    pcibus = qpci_init_pc();

    dev = NULL;

    qpci_device_foreach(pcibus, 0x1af4, 0x1110, save_fn, &dev);

    g_assert(dev != NULL);



    return dev;

}
