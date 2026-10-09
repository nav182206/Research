/* 
 * Benchmark Sample ID : devign_4749
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=396f929762d10ba2c7b38f7e8a2276dd066be2d7
 */

static void monitor_start_input(void)

{

    readline_start("(qemu) ", 0, monitor_handle_command1, NULL);

}
