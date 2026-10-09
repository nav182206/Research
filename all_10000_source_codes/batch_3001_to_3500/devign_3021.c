/* 
 * Benchmark Sample ID : devign_3021
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=6f2d8978728c48ca46f5c01835438508aace5c64
 */

static always_inline target_phys_addr_t get_pgaddr (target_phys_addr_t sdr1,

                                                    int sdr_sh,

                                                    target_phys_addr_t hash,

                                                    target_phys_addr_t mask)

{

    return (sdr1 & ((target_ulong)(-1ULL) << sdr_sh)) | (hash & mask);

}
