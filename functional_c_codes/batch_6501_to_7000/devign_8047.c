/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8047
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a1aa1309892581972b5019ef65fd0a12cd69cc28
 */

static void spapr_phb_vfio_instance_init(Object *obj)

{

    error_report("spapr-pci-vfio-host-bridge is deprecated");

}
