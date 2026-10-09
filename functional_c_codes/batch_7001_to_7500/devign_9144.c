/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9144
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static int get_int16(QEMUFile *f, void *pv, size_t size)

{

    int16_t *v = pv;

    qemu_get_sbe16s(f, v);

    return 0;

}
