/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9165
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ef29a70d18c2d551cf4bb74b8aa9638caac3391b
 */

static int cris_mmu_enabled(uint32_t rw_gc_cfg)

{

	return (rw_gc_cfg & 12) != 0;

}
