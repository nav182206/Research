/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7535
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e1219cdaf9fb4bc8cea410e1caf802373c1bfe51
 */

static char *doubles2str(double *dp, int count, const char *sep)

{

    int i;

    char *ap, *ap0;

    int component_len;

    if (!sep) sep = ", ";

    component_len = 15 + strlen(sep);

    ap = av_malloc(component_len * count);

    if (!ap)

        return NULL;

    ap0   = ap;

    ap[0] = '\0';

    for (i = 0; i < count; i++) {

        unsigned l = snprintf(ap, component_len, "%f%s", dp[i], sep);

        if(l >= component_len) {

            av_free(ap0);

            return NULL;

        }

        ap += l;

    }

    ap0[strlen(ap0) - strlen(sep)] = '\0';

    return ap0;

}
