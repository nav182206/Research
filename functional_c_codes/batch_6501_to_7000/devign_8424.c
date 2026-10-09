/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8424
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4a1418e07bdcfaa3177739e04707ecaec75d89e1
 */

void kqemu_flush(CPUState *env, int global)

{

    LOG_INT("kqemu_flush:\n");

    nb_pages_to_flush = KQEMU_FLUSH_ALL;

}
