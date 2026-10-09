/* 
 * Benchmark Sample ID : devign_4322
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=53628efbc8aa7a7ab5354d24b971f4d69452151d
 */

static int qemu_chr_fe_write_buffer(CharDriverState *s, const uint8_t *buf, int len, int *offset)

{

    int res = 0;

    *offset = 0;



    qemu_mutex_lock(&s->chr_write_lock);

    while (*offset < len) {

        do {

            res = s->chr_write(s, buf + *offset, len - *offset);

            if (res == -1 && errno == EAGAIN) {

                g_usleep(100);

            }

        } while (res == -1 && errno == EAGAIN);



        if (res <= 0) {

            break;

        }



        *offset += res;

    }

    if (*offset > 0) {

        qemu_chr_fe_write_log(s, buf, *offset);

    }

    qemu_mutex_unlock(&s->chr_write_lock);



    return res;

}
