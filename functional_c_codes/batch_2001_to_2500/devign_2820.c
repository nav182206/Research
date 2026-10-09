/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2820
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=59b060be184aff59cfa101c937c8139e66f452f2
 */

int qcrypto_pbkdf2_count_iters(QCryptoHashAlgorithm hash,

                               const uint8_t *key, size_t nkey,

                               const uint8_t *salt, size_t nsalt,

                               Error **errp)

{

    uint8_t out[32];

    long long int iterations = (1 << 15);

    unsigned long long delta_ms, start_ms, end_ms;



    while (1) {

        if (qcrypto_pbkdf2_get_thread_cpu(&start_ms, errp) < 0) {

            return -1;

        }

        if (qcrypto_pbkdf2(hash,

                           key, nkey,

                           salt, nsalt,

                           iterations,

                           out, sizeof(out),

                           errp) < 0) {

            return -1;

        }

        if (qcrypto_pbkdf2_get_thread_cpu(&end_ms, errp) < 0) {

            return -1;

        }



        delta_ms = end_ms - start_ms;



        if (delta_ms > 500) {

            break;

        } else if (delta_ms < 100) {

            iterations = iterations * 10;

        } else {

            iterations = (iterations * 1000 / delta_ms);

        }

    }



    iterations = iterations * 1000 / delta_ms;



    if (iterations > INT32_MAX) {

        error_setg(errp, "Iterations %lld too large for a 32-bit int",

                   iterations);

        return -1;

    }



    return iterations;

}
