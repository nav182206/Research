/* 
 * Benchmark Sample ID : devign_4693
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=edf779ffccc836661a7b654d320571a6c220caea
 */

static inline void memcpy_tofs(void * to, const void * from, unsigned long n)

{

	memcpy(to, from, n);

}
