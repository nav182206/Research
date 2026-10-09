/* 
 * Benchmark Sample ID : devign_6962
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0919ac787641db11024912651f3bc5764d4f1286
 */

inline qemu_irq omap_inth_get_pin(struct omap_intr_handler_s *s, int n)

{

    return s->pins[n];

}
