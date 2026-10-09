/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5810
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=33577b47c64435fcc2a1bc01c7e82534256f1fc3
 */

int qemu_chr_fe_ioctl(CharDriverState *s, int cmd, void *arg)

{

    if (!s->chr_ioctl)

        return -ENOTSUP;

    return s->chr_ioctl(s, cmd, arg);

}
