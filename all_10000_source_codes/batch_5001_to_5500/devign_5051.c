/* 
 * Benchmark Sample ID : devign_5051
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=548f52ea06951c20f0b91cae6cde0512ec073c83
 */

int qemu_get_buffer(QEMUFile *f, uint8_t *buf, int size)

{

    int pending = size;

    int done = 0;



    while (pending > 0) {

        int res;



        res = qemu_peek_buffer(f, buf, pending, 0);

        if (res == 0) {

            return done;

        }

        qemu_file_skip(f, res);

        buf += res;

        pending -= res;

        done += res;

    }

    return done;

}
