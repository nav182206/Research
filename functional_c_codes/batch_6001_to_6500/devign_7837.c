/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7837
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=becf8217deb2afc347d5172d9f30c8a8964b8b27
 */

void HELPER(diag)(CPUS390XState *env, uint32_t r1, uint32_t r3, uint32_t num)

{

    uint64_t r;



    switch (num) {

    case 0x500:

        /* KVM hypercall */

        qemu_mutex_lock_iothread();

        r = s390_virtio_hypercall(env);

        qemu_mutex_unlock_iothread();

        break;

    case 0x44:

        /* yield */

        r = 0;

        break;

    case 0x308:

        /* ipl */

        handle_diag_308(env, r1, r3);

        r = 0;

        break;

    default:

        r = -1;

        break;

    }



    if (r) {

        program_interrupt(env, PGM_OPERATION, ILEN_LATER_INC);

    }

}
