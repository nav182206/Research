/* 
 * Benchmark Sample ID : devign_1603
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b35c1f3361ebf6ec9ea5022903af4b559bff6063
 */

size_t qcrypto_hash_digest_len(QCryptoHashAlgorithm alg)

{

    if (alg >= G_N_ELEMENTS(qcrypto_hash_alg_size)) {

        return 0;

    }

    return qcrypto_hash_alg_size[alg];

}
