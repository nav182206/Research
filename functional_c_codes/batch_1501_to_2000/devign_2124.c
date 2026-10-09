/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2124
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=33577b47c64435fcc2a1bc01c7e82534256f1fc3
 */

int qemu_chr_fe_write_all(CharDriverState *s, const uint8_t *buf, int len)

{

    int offset = 0;

    int res = 0;



    qemu_mutex_lock(&s->chr_write_lock);

    while (offset < len) {

        do {

            res = s->chr_write(s, buf + offset, len - offset);

            if (res == -1 && errno == EAGAIN) {

                g_usleep(100);

            }

        } while (res == -1 && errno == EAGAIN);



        if (res <= 0) {

            break;

        }



        offset += res;

    }

    if (offset > 0) {

        qemu_chr_fe_write_log(s, buf, offset);

    }



    qemu_mutex_unlock(&s->chr_write_lock);



    if (res < 0) {

        return res;

    }

    return offset;

}
