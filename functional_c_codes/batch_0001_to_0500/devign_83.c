/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_83
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=91bfcdb01d4869aa8f4cb67007827de63b8c2217
 */

int qcrypto_init(Error **errp)

{

    int ret;

    ret = gnutls_global_init();

    if (ret < 0) {

        error_setg(errp,

                   "Unable to initialize GNUTLS library: %s",

                   gnutls_strerror(ret));

        return -1;

    }

#ifdef DEBUG_GNUTLS

    gnutls_global_set_log_level(10);

    gnutls_global_set_log_function(qcrypto_gnutls_log);

#endif



#ifdef CONFIG_GNUTLS_GCRYPT

    if (!gcry_check_version(GCRYPT_VERSION)) {

        error_setg(errp, "Unable to initialize gcrypt");

        return -1;

    }

#ifdef QCRYPTO_INIT_GCRYPT_THREADS

    gcry_control(GCRYCTL_SET_THREAD_CBS, &qcrypto_gcrypt_thread_impl);

#endif /* QCRYPTO_INIT_GCRYPT_THREADS */

    gcry_control(GCRYCTL_INITIALIZATION_FINISHED, 0);

#endif



    return 0;

}
