/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2678
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=70f8ee395afda6d96b15cb9a5b311af7720dded0
 */

static void msix_set_pending(PCIDevice *dev, int vector)

{

    *msix_pending_byte(dev, vector) |= msix_pending_mask(vector);

}
