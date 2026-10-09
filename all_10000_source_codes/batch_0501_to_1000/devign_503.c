/* 
 * Benchmark Sample ID : devign_503
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=fdcf6e65bce1f8972030fed7af5e8aa5f6ae92c6
 */

static int read_password(char *buf, int buf_size)

{

    int c, i;

    printf("Password: ");

    fflush(stdout);

    i = 0;

    for(;;) {

        c = getchar();

        if (c == '\n')

            break;

        if (i < (buf_size - 1))

            buf[i++] = c;

    }

    buf[i] = '\0';

    return 0;

}
