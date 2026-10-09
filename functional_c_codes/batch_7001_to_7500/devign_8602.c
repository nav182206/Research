/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8602
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7e84c2498f0ff3999937d18d1e9abaa030400000
 */

static inline void load_seg_vm(int seg, int selector)

{

    selector &= 0xffff;

    cpu_x86_load_seg_cache(env, seg, selector, 

                           (uint8_t *)(selector << 4), 0xffff, 0);

}
