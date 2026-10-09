/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2613
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=76349f5ba8f4e2f0b8c93c12ec0950a8bc77408a
 */

void restore_boot_order(void *opaque)

{

    char *normal_boot_order = opaque;

    static int first = 1;



    /* Restore boot order and remove ourselves after the first boot */

    if (first) {

        first = 0;

        return;

    }



    qemu_boot_set(normal_boot_order, NULL);



    qemu_unregister_reset(restore_boot_order, normal_boot_order);

    g_free(normal_boot_order);

}
