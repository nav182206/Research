/* 
 * Benchmark Sample ID : devign_5065
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9aebf3b89281a173d2dfeee379b800be5e3f363e
 */

static int id_wellformed(const char *id)

{

    int i;



    if (!qemu_isalpha(id[0])) {

        return 0;

    }

    for (i = 1; id[i]; i++) {

        if (!qemu_isalnum(id[i]) && !strchr("-._", id[i])) {

            return 0;

        }

    }

    return 1;

}
