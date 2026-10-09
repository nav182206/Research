/* 
 * Benchmark Sample ID : devign_9332
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f0df84c6c46cb632dac2d9fae5fdbe6001527c3b
 */

int select_watchdog_action(const char *p)

{

    int action;

    char *qapi_value;



    qapi_value = g_ascii_strdown(p, -1);

    action = qapi_enum_parse(&WatchdogAction_lookup, qapi_value, -1, NULL);

    g_free(qapi_value);

    if (action < 0)

        return -1;

    watchdog_action = action;

    return 0;

}
