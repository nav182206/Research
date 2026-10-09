/* 
 * Benchmark Sample ID : devign_6417
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4a1418e07bdcfaa3177739e04707ecaec75d89e1
 */

void helper_lret_protected(int shift, int addend)

{

    helper_ret_protected(shift, 0, addend);

#ifdef CONFIG_KQEMU

    if (kqemu_is_ok(env)) {

        env->exception_index = -1;

        cpu_loop_exit();

    }

#endif

}
