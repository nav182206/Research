/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_484
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7df9381b7aa56c897e344f3bfe43bf5848bbd3e0
 */

static bool vfio_pci_host_match(PCIHostDeviceAddress *host1,

                                PCIHostDeviceAddress *host2)

{

    return (host1->domain == host2->domain && host1->bus == host2->bus &&

            host1->slot == host2->slot && host1->function == host2->function);

}
