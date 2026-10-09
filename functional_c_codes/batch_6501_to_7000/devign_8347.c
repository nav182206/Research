/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8347
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d2963631dd54ddf0f46c151b7e3013e39bb78d3b
 */

static bool addrrange_intersects(AddrRange r1, AddrRange r2)

{

    return (r1.start >= r2.start && r1.start < r2.start + r2.size)

        || (r2.start >= r1.start && r2.start < r1.start + r1.size);

}
