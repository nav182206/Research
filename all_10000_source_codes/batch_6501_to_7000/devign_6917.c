/* 
 * Benchmark Sample ID : devign_6917
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=61b9251a3aaa65e65c4aab3a6800e884bb3b82f9
 */

qcrypto_tls_creds_x509_unload(QCryptoTLSCredsX509 *creds)

{

    if (creds->data) {

        gnutls_certificate_free_credentials(creds->data);

        creds->data = NULL;
