/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7723
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=aedbe19297907143f17b733a7ff0e0534377bed1
 */

void qemu_system_reset_request(void)

{

    if (no_reboot) {

        shutdown_requested = 1;

    } else {

        reset_requested = 1;

    }

    cpu_stop_current();

    qemu_notify_event();

}
