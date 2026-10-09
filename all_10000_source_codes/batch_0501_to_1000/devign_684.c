/* 
 * Benchmark Sample ID : devign_684
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ac3107340fbb9422ea63ee5d6729775965e121fd
 */

void qemu_chr_be_write(CharDriverState *s, uint8_t *buf, int len)

{

    s->chr_read(s->handler_opaque, buf, len);

}
