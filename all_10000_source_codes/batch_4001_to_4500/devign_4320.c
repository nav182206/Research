/* 
 * Benchmark Sample ID : devign_4320
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5070570c9089b905dd9efae30ee4318033c6ccd6
 */

static int find_debugfs(char *debugfs)

{

    char type[100];

    FILE *fp;



    fp = fopen("/proc/mounts", "r");

    if (fp == NULL) {

        return 0;

    }



    while (fscanf(fp, "%*s %" STR(PATH_MAX) "s %99s %*s %*d %*d\n",

                  debugfs, type) == 2) {

        if (strcmp(type, "debugfs") == 0) {

            break;

        }

    }

    fclose(fp);



    if (strcmp(type, "debugfs") != 0) {

        return 0;

    }

    return 1;

}
