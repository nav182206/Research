/* 
 * Benchmark Sample ID : devign_9756
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0a852417564bc59441dc09509beacf7b49bc1e57
 */

bool trace_init_backends(void)
{
#ifdef CONFIG_TRACE_SIMPLE
    if (!st_init()) {
        fprintf(stderr, "failed to initialize simple tracing backend.\n");
        return false;
    }
#ifdef CONFIG_TRACE_FTRACE
    if (!ftrace_init()) {
        fprintf(stderr, "failed to initialize ftrace backend.\n");
        return false;
    }
    return true;
}
