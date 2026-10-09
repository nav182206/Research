/* 
 * Benchmark Sample ID : devign_6726
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ad96090a01d848df67d70c5259ed8aa321fa8716
 */

void qemu_service_io(void)

{

    qemu_notify_event();

}
