/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1901
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=daa76aa416b1e18ab1fac650ff53d966d8f21f68
 */

static void handle_arg_log_filename(const char *arg)

{

    qemu_set_log_filename(arg);

}
