/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9807
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=bac05aa9a77af1ca7972c8dc07560f4daa7c2dfc
 */

void qemu_system_guest_panicked(void)

{




    qapi_event_send_guest_panicked(GUEST_PANIC_ACTION_PAUSE, &error_abort);

    vm_stop(RUN_STATE_GUEST_PANICKED);
