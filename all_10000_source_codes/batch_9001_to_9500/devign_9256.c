/* 
 * Benchmark Sample ID : devign_9256
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=85390939190e4b7eeba57765e344947c328cd166
 */

static void do_safe_dpy_refresh(CPUState *cpu, run_on_cpu_data opaque)

{

    DisplayChangeListener *dcl = opaque.host_ptr;


    dcl->ops->dpy_refresh(dcl);


}
