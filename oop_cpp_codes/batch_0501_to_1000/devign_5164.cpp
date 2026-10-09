/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5164
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=70f8ee395afda6d96b15cb9a5b311af7720dded0
 */

static bool msix_vector_masked(PCIDevice *dev, int vector, bool fmask)

{

    unsigned offset = vector * PCI_MSIX_ENTRY_SIZE + PCI_MSIX_ENTRY_VECTOR_CTRL;

    return fmask || dev->msix_table[offset] & PCI_MSIX_ENTRY_CTRL_MASKBIT;

}
