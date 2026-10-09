/* 
 * Benchmark Sample ID : devign_6299
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

void qemu_del_vm_change_state_handler(VMChangeStateEntry *e)

{

    LIST_REMOVE (e, entries);

    qemu_free (e);

}
