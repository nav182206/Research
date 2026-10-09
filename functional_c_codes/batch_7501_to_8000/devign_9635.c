/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9635
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=21ce148c7ec71ee32834061355a5ecfd1a11f90f
 */

static inline int cris_bound_b(int v, int b)

{

	int r = v;

	asm ("bound.b\t%1, %0\n" : "+r" (r) : "ri" (b));

	return r;

}
