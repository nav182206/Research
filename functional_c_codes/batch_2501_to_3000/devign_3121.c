/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3121
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e1f2641b5926d20f63d36f0de45206be774da8da
 */

static void monitor_puts(Monitor *mon, const char *str)

{

    char c;



    for(;;) {

        assert(mon->outbuf_index < sizeof(mon->outbuf) - 1);

        c = *str++;

        if (c == '\0')

            break;

        if (c == '\n')

            mon->outbuf[mon->outbuf_index++] = '\r';

        mon->outbuf[mon->outbuf_index++] = c;

        if (mon->outbuf_index >= (sizeof(mon->outbuf) - 1)

            || c == '\n')

            monitor_flush(mon);

    }

}
