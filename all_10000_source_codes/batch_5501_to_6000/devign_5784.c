/* 
 * Benchmark Sample ID : devign_5784
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7d1b0095bff7157e856d1d0e6c4295641ced2752
 */

static void gen_logicq_cc(TCGv_i64 val)

{

    TCGv tmp = new_tmp();

    gen_helper_logicq_cc(tmp, val);

    gen_logic_CC(tmp);

    dead_tmp(tmp);

}
