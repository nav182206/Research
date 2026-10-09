/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7618
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=30fb2ca603e8b8d0f02630ef18bc0d0637a88ffa
 */

int do_balloon(Monitor *mon, const QDict *params,

	       MonitorCompletion cb, void *opaque)

{

    int ret;



    if (kvm_enabled() && !kvm_has_sync_mmu()) {

        qerror_report(QERR_KVM_MISSING_CAP, "synchronous MMU", "balloon");

        return -1;

    }



    ret = qemu_balloon(qdict_get_int(params, "value"), cb, opaque);

    if (ret == 0) {

        qerror_report(QERR_DEVICE_NOT_ACTIVE, "balloon");

        return -1;

    }



    cb(opaque, NULL);

    return 0;

}
