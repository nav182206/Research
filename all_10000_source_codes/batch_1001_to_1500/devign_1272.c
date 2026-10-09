/* 
 * Benchmark Sample ID : devign_1272
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=79ca616f291124d166ca173e512c4ace1c2fe8b2
 */

void do_pci_device_hot_remove(Monitor *mon, const QDict *qdict)

{

    pci_device_hot_remove(mon, qdict_get_str(qdict, "pci_addr"));

}
