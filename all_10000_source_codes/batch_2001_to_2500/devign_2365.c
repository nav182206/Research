/* 
 * Benchmark Sample ID : devign_2365
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7bd427d801e1e3293a634d3c83beadaa90ffb911
 */

void qemu_announce_self(void)

{

	static QEMUTimer *timer;

	timer = qemu_new_timer(rt_clock, qemu_announce_self_once, &timer);

	qemu_announce_self_once(&timer);

}
