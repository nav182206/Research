/* 
 * Benchmark Sample ID : devign_3496
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2165477c0f65d20fdfbdb2ddcd4e0e7fe8f61df5
 */

int qcrypto_hash_bytesv(QCryptoHashAlgorithm alg,

                        const struct iovec *iov G_GNUC_UNUSED,

                        size_t niov G_GNUC_UNUSED,

                        uint8_t **result G_GNUC_UNUSED,

                        size_t *resultlen G_GNUC_UNUSED,

                        Error **errp)

{

    error_setg(errp,

               "Hash algorithm %d not supported without GNUTLS",

               alg);

    return -1;

}
