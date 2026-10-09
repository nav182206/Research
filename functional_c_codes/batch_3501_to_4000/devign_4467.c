/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4467
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=aedbe19297907143f17b733a7ff0e0534377bed1
 */

void qemu_system_shutdown_request(void)

{

    trace_qemu_system_shutdown_request();

    replay_shutdown_request();

    shutdown_requested = 1;

    qemu_notify_event();

}
