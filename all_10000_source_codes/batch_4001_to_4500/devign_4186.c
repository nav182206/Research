/* 
 * Benchmark Sample ID : devign_4186
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3a661f1eabf7e8db66e28489884d9b54aacb94ea
 */

int qcrypto_cipher_decrypt(QCryptoCipher *cipher,
                           const void *in,
                           void *out,
                           size_t len,
                           Error **errp)
{
    QCryptoCipherBuiltin *ctxt = cipher->opaque;
    return ctxt->decrypt(cipher, in, out, len, errp);
