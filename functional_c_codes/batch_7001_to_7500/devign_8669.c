/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8669
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

static void put_bool(QEMUFile *f, void *pv, size_t size)

{

    bool *v = pv;

    qemu_put_byte(f, *v);

}
