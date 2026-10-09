/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7547
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7e2515e87c41e2e658aaed466e11cbdf1ea8bcb1
 */

static void do_info_history (void)

{

    int i;



    for (i = 0; i < TERM_MAX_CMDS; i++) {

	if (term_history[i] == NULL)

	    break;

	term_printf("%d: '%s'\n", i, term_history[i]);

    }

}
