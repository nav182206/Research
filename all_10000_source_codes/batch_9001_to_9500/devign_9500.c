/* 
 * Benchmark Sample ID : devign_9500
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static int get_uint64(QEMUFile *f, void *pv, size_t size)

{

    uint64_t *v = pv;

    qemu_get_be64s(f, v);

    return 0;

}
