/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2300
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=33577b47c64435fcc2a1bc01c7e82534256f1fc3
 */

void qemu_chr_be_write(CharDriverState *s, uint8_t *buf, int len)

{

    if (s->chr_read) {

        s->chr_read(s->handler_opaque, buf, len);

    }

}
