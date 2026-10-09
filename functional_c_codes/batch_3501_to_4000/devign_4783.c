/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4783
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b5538c300a56c3cfb33022840fe0b4968147e7a
 */

static void __attribute__((constructor)) st_init(void)

{

    atexit(st_flush_trace_buffer);

}
