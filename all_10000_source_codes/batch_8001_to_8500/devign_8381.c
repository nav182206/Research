/* 
 * Benchmark Sample ID : devign_8381
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=196a778428989217b82de042725dc8eb29c8f8d8
 */

void qemu_spice_vm_change_state_handler(void *opaque, int running, int reason)

{

    SimpleSpiceDisplay *ssd = opaque;



    if (running) {

        ssd->worker->start(ssd->worker);

    } else {

        qemu_mutex_unlock_iothread();

        ssd->worker->stop(ssd->worker);

        qemu_mutex_lock_iothread();

    }

    ssd->running = running;

}
