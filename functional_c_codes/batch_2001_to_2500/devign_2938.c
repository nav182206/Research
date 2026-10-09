/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2938
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=12de9a396acbc95e25c5d60ed097cc55777eaaed
 */

static inline target_phys_addr_t get_pgaddr (target_phys_addr_t sdr1,

                                             int sdr_sh,

                                             target_phys_addr_t hash,

                                             target_phys_addr_t mask)

{

    return (sdr1 & ((target_ulong)(-1ULL) << sdr_sh)) | (hash & mask);

}
