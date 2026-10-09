/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4802
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e1f2641b5926d20f63d36f0de45206be774da8da
 */

void monitor_vprintf(Monitor *mon, const char *fmt, va_list ap)

{

    char buf[4096];



    if (!mon)

        return;



    if (monitor_ctrl_mode(mon)) {

        return;

    }



    vsnprintf(buf, sizeof(buf), fmt, ap);

    monitor_puts(mon, buf);

}
