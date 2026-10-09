/* 
 * Benchmark Sample ID : devign_9592
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=30fb2ca603e8b8d0f02630ef18bc0d0637a88ffa
 */

void qemu_add_balloon_handler(QEMUBalloonEvent *func, void *opaque)

{

    balloon_event_fn = func;

    balloon_opaque = opaque;

}
