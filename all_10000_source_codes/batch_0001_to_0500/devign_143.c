/* 
 * Benchmark Sample ID : devign_143
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f1839938b090b28537d9be2c1b255b834f3cfbb8
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



    qemu_boot_set(normal_boot_order);



    qemu_unregister_reset(restore_boot_order, normal_boot_order);

    g_free(normal_boot_order);

}
