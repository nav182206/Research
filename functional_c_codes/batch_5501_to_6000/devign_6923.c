/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6923
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=32c813e6c2a857b93b897901b7e20281397528a3
 */

size_t qcrypto_cipher_get_block_len(QCryptoCipherAlgorithm alg)

{

    if (alg >= G_N_ELEMENTS(alg_key_len)) {

        return 0;

    }

    return alg_block_len[alg];

}
