/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4922
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8417cebfda193c7f9ca70be5e308eaa92cf84b94
 */

static AddrRange addrrange_make(uint64_t start, uint64_t size)

{

    return (AddrRange) { start, size };

}
