/* 
 * Benchmark Sample ID : devign_523
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4f8586144161d5e680fdef3e09b7e8e9111c2929
 */

int qemu_chr_fe_get_msgfd(CharDriverState *s)

{

    int fd;

    return (qemu_chr_fe_get_msgfds(s, &fd, 1) >= 0) ? fd : -1;

}
