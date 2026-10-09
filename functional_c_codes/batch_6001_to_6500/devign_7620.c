/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7620
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

uint64_t qemu_get_be64(QEMUFile *f)

{

    uint64_t v;

    v = (uint64_t)qemu_get_be32(f) << 32;

    v |= qemu_get_be32(f);

    return v;

}
