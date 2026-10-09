/* 
 * Benchmark Sample ID : devign_9588
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=062ba099e01ff1474be98c0a4f3da351efab5d9d
 */

int kvm_arm_sync_mpstate_to_qemu(ARMCPU *cpu)

{

    if (cap_has_mp_state) {

        struct kvm_mp_state mp_state;

        int ret = kvm_vcpu_ioctl(CPU(cpu), KVM_GET_MP_STATE, &mp_state);

        if (ret) {

            fprintf(stderr, "%s: failed to get MP_STATE %d/%s\n",

                    __func__, ret, strerror(-ret));

            abort();

        }

        cpu->powered_off = (mp_state.mp_state == KVM_MP_STATE_STOPPED);

    }



    return 0;

}
