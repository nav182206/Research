/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4969
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=74892d2468b9f0c56b915ce94848d6f7fac39740
 */

static bool qemu_vmstop_requested(RunState *r)

{

    if (vmstop_requested < RUN_STATE_MAX) {

        *r = vmstop_requested;

        vmstop_requested = RUN_STATE_MAX;

        return true;

    }



    return false;

}
