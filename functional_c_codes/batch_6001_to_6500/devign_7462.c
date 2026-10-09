/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7462
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b7680cb6078bd7294a3dd86473d3f2fdee991dd0
 */

void vm_stop(int reason)

{

    QemuThread me;

    qemu_thread_self(&me);



    if (!qemu_thread_equal(&me, &io_thread)) {

        qemu_system_vmstop_request(reason);

        /*

         * FIXME: should not return to device code in case

         * vm_stop() has been requested.

         */

        cpu_stop_current();

        return;

    }

    do_vm_stop(reason);

}
