/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_593
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=04920fc0faa4760f9c4fc0e73b992b768099be70
 */

static void pc_q35_init_1_6(QEMUMachineInitArgs *args)

{

    has_pci_info = false;


    pc_q35_init(args);

}
