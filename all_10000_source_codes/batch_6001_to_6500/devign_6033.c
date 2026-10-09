/* 
 * Benchmark Sample ID : devign_6033
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=541be9274e8ef227fb1b50ce124fd2cc2dce81a5
 */

void kvm_setup_guest_memory(void *start, size_t size)

{

#ifdef CONFIG_VALGRIND_H

    VALGRIND_MAKE_MEM_DEFINED(start, size);

#endif

    if (!kvm_has_sync_mmu()) {

        int ret = qemu_madvise(start, size, QEMU_MADV_DONTFORK);



        if (ret) {

            perror("qemu_madvise");

            fprintf(stderr,

                    "Need MADV_DONTFORK in absence of synchronous KVM MMU\n");

            exit(1);

        }

    }

}
