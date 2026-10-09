/* 
 * Benchmark Sample ID : devign_1490
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=299b520cd4092be3c53f8380b81315c33927d9d3
 */

static inline int compare_masked(uint64_t x, uint64_t y, uint64_t mask)

{

    return (x & mask) == (y & mask);

}
