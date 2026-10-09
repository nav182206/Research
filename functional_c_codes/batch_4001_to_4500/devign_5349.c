/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5349
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3e305e4a4752f70c0b5c3cf5b43ec957881714f7
 */

static gnutls_anon_server_credentials_t vnc_tls_initialize_anon_cred(void)

{

    gnutls_anon_server_credentials_t anon_cred;

    int ret;



    if ((ret = gnutls_anon_allocate_server_credentials(&anon_cred)) < 0) {

        VNC_DEBUG("Cannot allocate credentials %s\n", gnutls_strerror(ret));

        return NULL;

    }



    gnutls_anon_set_server_dh_params(anon_cred, dh_params);



    return anon_cred;

}
