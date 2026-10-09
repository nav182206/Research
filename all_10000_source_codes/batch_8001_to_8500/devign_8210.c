/* 
 * Benchmark Sample ID : devign_8210
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=21ce148c7ec71ee32834061355a5ecfd1a11f90f
 */

static inline int cris_lz(int x)

{

	int r;

	asm ("lz\t%1, %0\n" : "=r" (r) : "r" (x));

	return r;

}
