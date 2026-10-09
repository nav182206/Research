/* 
 * Benchmark Sample ID : devign_9342
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d045c466d9e62b4321fadf586d024d54ddfd8bd4
 */

iscsi_process_read(void *arg)

{

    IscsiLun *iscsilun = arg;

    struct iscsi_context *iscsi = iscsilun->iscsi;



    aio_context_acquire(iscsilun->aio_context);

    iscsi_service(iscsi, POLLIN);

    iscsi_set_events(iscsilun);

    aio_context_release(iscsilun->aio_context);

}
