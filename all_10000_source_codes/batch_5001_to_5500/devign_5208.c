/* 
 * Benchmark Sample ID : devign_5208
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=12d4536f7d911b6d87a766ad7300482ea663cea2
 */

static int64_t qemu_icount_delta(void)

{

    if (!use_icount) {

        return 5000 * (int64_t) 1000000;

    } else if (use_icount == 1) {

        /* When not using an adaptive execution frequency

           we tend to get badly out of sync with real time,

           so just delay for a reasonable amount of time.  */

        return 0;

    } else {

        return cpu_get_icount() - cpu_get_clock();

    }

}
