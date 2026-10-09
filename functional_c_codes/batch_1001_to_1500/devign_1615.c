/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1615
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ba7806ad92a2f6b1625cfa67d44dc1b71e3be44e
 */

void add_user_command(char *optarg)

{

    ncmdline++;

    cmdline = realloc(cmdline, ncmdline * sizeof(char *));

    if (!cmdline) {

        perror("realloc");

        exit(1);

    }

    cmdline[ncmdline-1] = optarg;

}
