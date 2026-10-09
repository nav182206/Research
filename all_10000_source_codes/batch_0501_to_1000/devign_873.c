/* 
 * Benchmark Sample ID : devign_873
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e82d5a2460b0e176128027651ff9b104e4bdf5cc
 */

void tcg_gen_mb(TCGBar mb_type)

{

    if (parallel_cpus) {

        tcg_gen_op1(INDEX_op_mb, mb_type);

    }

}
