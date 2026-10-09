/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4705
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f74990a5d019751c545e9800a3376b6336e77d38
 */

void HELPER(stfl)(CPUS390XState *env)

{

    uint64_t words[MAX_STFL_WORDS];

    LowCore *lowcore;



    lowcore = cpu_map_lowcore(env);

    do_stfle(env, words);

    lowcore->stfl_fac_list = cpu_to_be32(words[0] >> 32);

    cpu_unmap_lowcore(lowcore);

}
