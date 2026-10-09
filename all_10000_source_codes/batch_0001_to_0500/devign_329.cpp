/* 
 * Benchmark Sample ID : devign_329
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=37f51384ae05bd50f83308339dbffa3e78404874
 */

static inline bool vtd_iova_range_check(uint64_t iova, VTDContextEntry *ce)

{

    /*

     * Check if @iova is above 2^X-1, where X is the minimum of MGAW

     * in CAP_REG and AW in context-entry.

     */

    return !(iova & ~(vtd_iova_limit(ce) - 1));

}
