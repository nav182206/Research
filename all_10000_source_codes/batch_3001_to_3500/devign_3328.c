/* 
 * Benchmark Sample ID : devign_3328
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ede085b3fedfde36cb566968c4efcfbad4845af1
 */

static bool main_loop_should_exit(void)

{

    RunState r;

    if (qemu_debug_requested()) {

        vm_stop(RUN_STATE_DEBUG);

    }

    if (qemu_suspend_requested()) {

        qemu_system_suspend();

    }

    if (qemu_shutdown_requested()) {

        qemu_kill_report();

        monitor_protocol_event(QEVENT_SHUTDOWN, NULL);

        if (no_shutdown) {

            vm_stop(RUN_STATE_SHUTDOWN);

        } else {

            return true;

        }

    }

    if (qemu_reset_requested()) {

        pause_all_vcpus();

        cpu_synchronize_all_states();

        qemu_system_reset(VMRESET_REPORT);

        resume_all_vcpus();

        if (runstate_check(RUN_STATE_INTERNAL_ERROR) ||

            runstate_check(RUN_STATE_SHUTDOWN)) {

            runstate_set(RUN_STATE_PAUSED);

        }

    }

    if (qemu_wakeup_requested()) {

        pause_all_vcpus();

        cpu_synchronize_all_states();

        qemu_system_reset(VMRESET_SILENT);

        resume_all_vcpus();

        monitor_protocol_event(QEVENT_WAKEUP, NULL);

    }

    if (qemu_powerdown_requested()) {

        qemu_system_powerdown();

    }

    if (qemu_vmstop_requested(&r)) {

        vm_stop(r);

    }

    return false;

}
