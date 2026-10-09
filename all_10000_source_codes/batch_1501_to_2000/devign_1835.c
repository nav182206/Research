/* 
 * Benchmark Sample ID : devign_1835
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7372c2b926200db295412efbb53f93773b7f1754
 */

static inline void qemu_assert(int cond, const char *msg)

{

    if (!cond) {

        fprintf (stderr, "badness: %s\n", msg);

        abort();

    }

}
