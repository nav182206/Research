/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5598
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=87f25c12bfeaaa0c41fb857713bbc7e8a9b757dc
 */

static inline void gdb_continue(GDBState *s)

{

#ifdef CONFIG_USER_ONLY

    s->running_state = 1;

#else

    vm_start();

#endif

}
