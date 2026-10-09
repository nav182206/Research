/* 
 * Benchmark Sample ID : devign_4090
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=70ae65f5d91462e1905a53236179fde21cda3a2f
 */

static PCIIDEState *pci_from_bm(BMDMAState *bm)

{

    return bm->pci_dev;

}
