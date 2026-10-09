/* 
 * Benchmark Sample ID : devign_4825
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9604f70fdf8e21ec0dbf6eac5e59a0eb8beadd64
 */

static void pc_q35_init_1_5(QEMUMachineInitArgs *args)

{

    has_pci_info = false;

    pc_q35_init(args);

}
