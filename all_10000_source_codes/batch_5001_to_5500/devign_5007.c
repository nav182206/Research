/* 
 * Benchmark Sample ID : devign_5007
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=6502a14734e71b2f6dd079b0a1e546e6aa2d2f8d
 */

void qmp_balloon(int64_t value, Error **errp)

{

    if (kvm_enabled() && !kvm_has_sync_mmu()) {

        error_set(errp, QERR_KVM_MISSING_CAP, "synchronous MMU", "balloon");

        return;

    }



    if (value <= 0) {

        error_set(errp, QERR_INVALID_PARAMETER_VALUE, "target", "a size");

        return;

    }

    

    if (qemu_balloon(value) == 0) {

        error_set(errp, QERR_DEVICE_NOT_ACTIVE, "balloon");

    }

}
