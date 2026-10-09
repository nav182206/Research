/* 
 * Benchmark Sample ID : devign_8879
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3996e85c1822e05c50250f8d2d1e57b6bea1229d
 */

static void xen_hvm_change_state_handler(void *opaque, int running,

                                         RunState rstate)

{

    if (running) {

        xen_main_loop_prepare((XenIOState *)opaque);

    }

}
