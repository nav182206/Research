/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5138
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=21ce148c7ec71ee32834061355a5ecfd1a11f90f
 */

static inline int cris_swap(const int mode, int x)

{

	switch (mode)

	{

		case N: asm ("swapn\t%0\n" : "+r" (x) : "0" (x)); break;

		case W: asm ("swapw\t%0\n" : "+r" (x) : "0" (x)); break;

		case B: asm ("swapb\t%0\n" : "+r" (x) : "0" (x)); break;

		case R: asm ("swapr\t%0\n" : "+r" (x) : "0" (x)); break;

		case B|R: asm ("swapbr\t%0\n" : "+r" (x) : "0" (x)); break;

		case W|R: asm ("swapwr\t%0\n" : "+r" (x) : "0" (x)); break;

		case W|B: asm ("swapwb\t%0\n" : "+r" (x) : "0" (x)); break;

		case W|B|R: asm ("swapwbr\t%0\n" : "+r" (x) : "0" (x)); break;

		case N|R: asm ("swapnr\t%0\n" : "+r" (x) : "0" (x)); break;

		case N|B: asm ("swapnb\t%0\n" : "+r" (x) : "0" (x)); break;

		case N|B|R: asm ("swapnbr\t%0\n" : "+r" (x) : "0" (x)); break;

		case N|W: asm ("swapnw\t%0\n" : "+r" (x) : "0" (x)); break;

		default:

			err();

			break;

	}

	return x;

}
