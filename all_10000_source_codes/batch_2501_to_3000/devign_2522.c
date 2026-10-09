/* 
 * Benchmark Sample ID : devign_2522
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

unsigned int qemu_get_be32(QEMUFile *f)

{

    unsigned int v;

    v = qemu_get_byte(f) << 24;

    v |= qemu_get_byte(f) << 16;

    v |= qemu_get_byte(f) << 8;

    v |= qemu_get_byte(f);

    return v;

}
