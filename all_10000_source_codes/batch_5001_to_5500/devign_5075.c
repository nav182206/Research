/* 
 * Benchmark Sample ID : devign_5075
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9a4c0e220d8a4f82b5665d0ee95ef94d8e1509d5
 */

static bool virtio_pci_modern_state_needed(void *opaque)

{

    VirtIOPCIProxy *proxy = opaque;



    return !(proxy->flags & VIRTIO_PCI_FLAG_DISABLE_MODERN);

}
