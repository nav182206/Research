/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7648
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=eb2a770b178b9040c3fc04ee31dc38d1775db09a
 */

static int qcrypto_cipher_setiv_aes(QCryptoCipher *cipher,

                                     const uint8_t *iv, size_t niv,

                                     Error **errp)

{

    QCryptoCipherBuiltin *ctxt = cipher->opaque;

    if (niv != 16) {

        error_setg(errp, "IV must be 16 bytes not %zu", niv);

        return -1;

    }



    g_free(ctxt->state.aes.iv);

    ctxt->state.aes.iv = g_new0(uint8_t, niv);

    memcpy(ctxt->state.aes.iv, iv, niv);

    ctxt->state.aes.niv = niv;



    return 0;

}
