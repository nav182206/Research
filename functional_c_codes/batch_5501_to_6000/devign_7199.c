/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7199
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=4f4f6976d80614e2d81cea4385885876f24bb257
 */

void qcrypto_cipher_free(QCryptoCipher *cipher)

{

    QCryptoCipherBuiltin *ctxt = cipher->opaque;

    if (!cipher) {

        return;

    }



    ctxt->free(cipher);

    g_free(cipher);

}
