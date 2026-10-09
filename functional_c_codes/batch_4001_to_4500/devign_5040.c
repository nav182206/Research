/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5040
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7e2515e87c41e2e658aaed466e11cbdf1ea8bcb1
 */

static void term_backward_char(void)

{

    if (term_cmd_buf_index > 0) {

        term_cmd_buf_index--;

    }

}
