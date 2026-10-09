/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5336
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=198a0039c5fca224a77e9761e2350dd9cc102ad0
 */

void vnc_flush(VncState *vs)

{

    if (vs->output.offset)

        vnc_client_write(vs);

}
