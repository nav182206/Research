/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6017
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=0c16c056a4f9dec18fdd56feec82a5db9ff3c15e
 */

gboolean qcrypto_hash_supports(QCryptoHashAlgorithm alg G_GNUC_UNUSED)

{

    return false;

}
