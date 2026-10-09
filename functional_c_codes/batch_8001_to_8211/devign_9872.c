/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9872
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=36778660d7fd0748a6129916e47ecedd67bdb758
 */

static inline bool valid_ptex(PowerPCCPU *cpu, target_ulong ptex)

{

    /*

     * hash value/pteg group index is normalized by htab_mask

     */

    if (((ptex & ~7ULL) / HPTES_PER_GROUP) & ~cpu->env.htab_mask) {

        return false;

    }

    return true;

}
