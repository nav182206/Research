/* 
 * Benchmark Sample ID : devign_915
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d57e4e482e3997b1382625c84149ad0b69155fc0
 */

static int read_password(char *buf, int buf_size)

{

    uint8_t ch;

    int i, ret;



    printf("password: ");

    fflush(stdout);

    term_init();

    i = 0;

    for(;;) {

        ret = read(0, &ch, 1);

        if (ret == -1) {

            if (errno == EAGAIN || errno == EINTR) {

                continue;

            } else {

                break;

            }

        } else if (ret == 0) {

            ret = -1;

            break;

        } else {

            if (ch == '\r') {

                ret = 0;

                break;

            }

            if (i < (buf_size - 1))

                buf[i++] = ch;

        }

    }

    term_exit();

    buf[i] = '\0';

    printf("\n");

    return ret;

}
