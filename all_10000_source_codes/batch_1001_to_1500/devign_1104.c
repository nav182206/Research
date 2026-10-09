/* 
 * Benchmark Sample ID : devign_1104
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3a720b14b9e09f8553832b835ede9933b70fe9a9
 */

void vm_start(void)

{

    if (!vm_running) {

        cpu_enable_ticks();

        vm_running = 1;

        vm_state_notify(1, 0);

        qemu_rearm_alarm_timer(alarm_timer);

        resume_all_vcpus();

    }

}
