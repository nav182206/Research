/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1758
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5839e53bbc0fec56021d758aab7610df421ed8c8
 */

static char **breakline(char *input, int *count)

{

    int c = 0;

    char *p;

    char **rval = g_malloc0(sizeof(char *));

    char **tmp;



    while (rval && (p = qemu_strsep(&input, " ")) != NULL) {

        if (!*p) {

            continue;

        }

        c++;

        tmp = g_realloc(rval, sizeof(*rval) * (c + 1));

        if (!tmp) {

            g_free(rval);

            rval = NULL;

            c = 0;

            break;

        } else {

            rval = tmp;

        }

        rval[c - 1] = p;

        rval[c] = NULL;

    }

    *count = c;

    return rval;

}
