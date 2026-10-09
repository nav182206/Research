/* 
 * Benchmark Sample ID : devign_2372
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=70f8ee395afda6d96b15cb9a5b311af7720dded0
 */

static bool msix_is_masked(PCIDevice *dev, int vector)

{

    return msix_vector_masked(dev, vector, dev->msix_function_masked);

}
