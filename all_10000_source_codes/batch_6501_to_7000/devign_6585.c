/* 
 * Benchmark Sample ID : devign_6585
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3a661f1eabf7e8db66e28489884d9b54aacb94ea
 */

int qcrypto_cipher_encrypt(QCryptoCipher *cipher,

                           const void *in,

                           void *out,

                           size_t len,

                           Error **errp)

{

    QCryptoCipherNettle *ctx = cipher->opaque;



    switch (cipher->mode) {

    case QCRYPTO_CIPHER_MODE_ECB:

        ctx->alg_encrypt(ctx->ctx_encrypt, len, out, in);

        break;



    case QCRYPTO_CIPHER_MODE_CBC:

        cbc_encrypt(ctx->ctx_encrypt, ctx->alg_encrypt,

                    ctx->niv, ctx->iv,

                    len, out, in);

        break;

    default:

        error_setg(errp, "Unsupported cipher algorithm %d",

                   cipher->alg);

        return -1;

    }

    return 0;

}
