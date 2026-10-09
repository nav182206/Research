/* 
 * Benchmark Sample ID : devign_2902
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3a4496903795e05c1e8367bb4c9862d5670f48d7
 */

static void handle_event(int event)

{

    static bool logged;



    if (event & ~PVPANIC_PANICKED && !logged) {

        qemu_log_mask(LOG_GUEST_ERROR, "pvpanic: unknown event %#x.\n", event);

        logged = true;

    }



    if (event & PVPANIC_PANICKED) {

        panicked_mon_event("pause");

        vm_stop(RUN_STATE_GUEST_PANICKED);

        return;

    }

}
