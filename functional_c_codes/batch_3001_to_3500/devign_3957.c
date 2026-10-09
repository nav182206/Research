/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3957
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f0aa7a8b2d518c54430e4382309281b93e51981a
 */

static void do_loadvm(Monitor *mon, const QDict *qdict)

{

    int saved_vm_running  = vm_running;

    const char *name = qdict_get_str(qdict, "name");



    vm_stop(0);



    if (load_vmstate(name) >= 0 && saved_vm_running)

        vm_start();

}
