/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6399
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c7cacb3e7a2e9fdf929c993b98268e4179147cbb
 */

static char *qemu_rbd_parse_clientname(const char *conf, char *clientname)

{

    const char *p = conf;



    while (*p) {

        int len;

        const char *end = strchr(p, ':');



        if (end) {

            len = end - p;

        } else {

            len = strlen(p);

        }



        if (strncmp(p, "id=", 3) == 0) {

            len -= 3;

            strncpy(clientname, p + 3, len);

            clientname[len] = '\0';

            return clientname;

        }

        if (end == NULL) {

            break;

        }

        p = end + 1;

    }

    return NULL;

}
