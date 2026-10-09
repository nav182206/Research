/* 
 * Benchmark Sample ID : devign_2482
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=922453bca6a927bb527068ae8679d587cfa45dbc
 */

static void do_vm_stop(RunState state)

{

    if (runstate_is_running()) {

        cpu_disable_ticks();

        pause_all_vcpus();

        runstate_set(state);

        vm_state_notify(0, state);

        qemu_aio_flush();

        bdrv_flush_all();

        monitor_protocol_event(QEVENT_STOP, NULL);

    }

}
