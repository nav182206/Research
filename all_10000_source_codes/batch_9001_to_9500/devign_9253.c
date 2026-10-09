/* 
 * Benchmark Sample ID : devign_9253
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=95ce326e5b47b4b841849f8a2ac7b96d6e204dfb
 */

static void term_print_cmdline (const char *cmdline)

{

    term_show_prompt();

    term_printf(cmdline);

    term_flush();

}
