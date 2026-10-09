/* 
 * Benchmark Sample ID : devign_3395
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8417cebfda193c7f9ca70be5e308eaa92cf84b94
 */

static uint64_t addrrange_end(AddrRange r)

{

    return r.start + r.size;

}
