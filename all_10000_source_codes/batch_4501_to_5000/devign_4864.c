/* 
 * Benchmark Sample ID : devign_4864
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7060b478d3f3a8bc7a282292609ff5aec6de1958
 */

static void monitor_read_command(Monitor *mon, int show_prompt)

{

    if (!mon->rs)

        return;



    readline_start(mon->rs, "(qemu) ", 0, monitor_command_cb, NULL);

    if (show_prompt)

        readline_show_prompt(mon->rs);

}
