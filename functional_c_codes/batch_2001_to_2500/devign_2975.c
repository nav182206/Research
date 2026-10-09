/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2975
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d354899c8279146f3e154b9ba1f7461abb7f5279
 */

static void listflags(char *buf, int bufsize, uint32_t fbits,

    const char **featureset, uint32_t flags)

{

    const char **p = &featureset[31];

    char *q, *b, bit;

    int nc;



    b = 4 <= bufsize ? buf + (bufsize -= 3) - 1 : NULL;

    *buf = '\0';

    for (q = buf, bit = 31; fbits && bufsize; --p, fbits &= ~(1 << bit), --bit)

        if (fbits & 1 << bit && (*p || !flags)) {

            if (*p)

                nc = snprintf(q, bufsize, "%s%s", q == buf ? "" : " ", *p);

            else

                nc = snprintf(q, bufsize, "%s[%d]", q == buf ? "" : " ", bit);

            if (bufsize <= nc) {

                if (b)

                    sprintf(b, "...");

                return;

            }

            q += nc;

            bufsize -= nc;

        }

}
