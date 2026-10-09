/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8329
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d73cd8f4ea1c2944bd16f7a1c445eaa25c9e6e26
 */

static int kvm_handle_internal_error(CPUState *env, struct kvm_run *run)

{

    fprintf(stderr, "KVM internal error.");

    if (kvm_check_extension(kvm_state, KVM_CAP_INTERNAL_ERROR_DATA)) {

        int i;



        fprintf(stderr, " Suberror: %d\n", run->internal.suberror);

        for (i = 0; i < run->internal.ndata; ++i) {

            fprintf(stderr, "extra data[%d]: %"PRIx64"\n",

                    i, (uint64_t)run->internal.data[i]);

        }

    } else {

        fprintf(stderr, "\n");

    }

    if (run->internal.suberror == KVM_INTERNAL_ERROR_EMULATION) {

        fprintf(stderr, "emulation failure\n");

        if (!kvm_arch_stop_on_emulation_error(env)) {

            cpu_dump_state(env, stderr, fprintf, CPU_DUMP_CODE);

            return 0;

        }

    }

    /* FIXME: Should trigger a qmp message to let management know

     * something went wrong.

     */

    return -1;

}
