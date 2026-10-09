/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_816
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static int get_uint32_equal(QEMUFile *f, void *pv, size_t size)

{

    uint32_t *v = pv;

    uint32_t v2;

    qemu_get_be32s(f, &v2);



    if (*v == v2) {

        return 0;

    }

    return -EINVAL;

}
