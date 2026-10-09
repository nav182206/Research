/* 
 * Benchmark Sample ID : devign_6153
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=21ce148c7ec71ee32834061355a5ecfd1a11f90f
 */

static inline void cris_fidx_d(unsigned int x)

{

	register unsigned int v asm("$r10") = x;

	asm ("fidxd\t[%0]\n" : : "r" (v) );

}
