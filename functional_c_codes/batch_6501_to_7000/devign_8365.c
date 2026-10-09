/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8365
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=86b5ab390992fd57f3a23764994a7e082bcc2fc4
 */

void HELPER(stfl)(CPUS390XState *env)

{

    uint64_t words[MAX_STFL_WORDS];



    do_stfle(env, words);

    cpu_stl_data(env, 200, words[0] >> 32);

}
