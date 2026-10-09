/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1343
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7faa8075d898ae56d2c533c530569bb25ab86eaf
 */

static void disable_device(PIIX4PMState *s, int slot)

{

    s->ar.gpe.sts[0] |= PIIX4_PCI_HOTPLUG_STATUS;

    s->pci0_status.down |= (1 << slot);

}
