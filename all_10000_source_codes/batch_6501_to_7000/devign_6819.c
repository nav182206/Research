/* 
 * Benchmark Sample ID : devign_6819
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=60fe637bf0e4d7989e21e50f52526444765c63b4
 */

int qemu_get_byte(QEMUFile *f)

{

    int result;



    result = qemu_peek_byte(f, 0);

    qemu_file_skip(f, 1);

    return result;

}
