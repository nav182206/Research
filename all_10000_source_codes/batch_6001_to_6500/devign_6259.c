/* 
 * Benchmark Sample ID : devign_6259
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7e2515e87c41e2e658aaed466e11cbdf1ea8bcb1
 */

static void term_eol(void)

{

    term_cmd_buf_index = term_cmd_buf_size;

}
