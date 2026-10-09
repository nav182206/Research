/* 
 * Benchmark Sample ID : devign_2346
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=30fb2ca603e8b8d0f02630ef18bc0d0637a88ffa
 */

static int qemu_balloon_status(MonitorCompletion cb, void *opaque)

{

    if (!balloon_event_fn) {

        return 0;

    }

    balloon_event_fn(balloon_opaque, 0, cb, opaque);

    return 1;

}
