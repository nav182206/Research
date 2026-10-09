/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2990
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6502a14734e71b2f6dd079b0a1e546e6aa2d2f8d
 */

static int qemu_balloon(ram_addr_t target)

{

    if (!balloon_event_fn) {

        return 0;

    }

    trace_balloon_event(balloon_opaque, target);

    balloon_event_fn(balloon_opaque, target);

    return 1;

}
