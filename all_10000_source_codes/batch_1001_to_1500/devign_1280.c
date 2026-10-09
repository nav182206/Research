/* 
 * Benchmark Sample ID : devign_1280
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3eadc68ebd174f5bad51fe6e0bbcf6d6651c784c
 */

void os_set_proc_name(const char *s)

{

#if defined(PR_SET_NAME)

    char name[16];

    if (!s)

        return;

    name[sizeof(name) - 1] = 0;

    strncpy(name, s, sizeof(name));

    /* Could rewrite argv[0] too, but that's a bit more complicated.

       This simple way is enough for `top'. */

    if (prctl(PR_SET_NAME, name)) {

        perror("unable to change process name");

        exit(1);

    }

#else

    fprintf(stderr, "Change of process name not supported by your OS\n");

    exit(1);

#endif

}
