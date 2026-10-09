/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1320
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f1839938b090b28537d9be2c1b255b834f3cfbb8
 */

int qemu_boot_set(const char *boot_order)

{

    if (!boot_set_handler) {

        return -EINVAL;

    }

    return boot_set_handler(boot_set_opaque, boot_order);

}
