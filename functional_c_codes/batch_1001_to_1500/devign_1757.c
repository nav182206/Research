/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1757
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=04920fc0faa4760f9c4fc0e73b992b768099be70
 */

static void pc_init_pci_1_6(QEMUMachineInitArgs *args)

{

    has_pci_info = false;


    pc_init_pci(args);

}
