/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2458
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a7812ae412311d7d47f8aa85656faadac9d64b56
 */

static inline void t_gen_raise_exception(uint32_t index)

{

	tcg_gen_helper_0_1(helper_raise_exception, tcg_const_tl(index));

}
