/* 
 * Benchmark Sample ID : devign_2224
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1687a089f103f9b7a1b4a1555068054cb46ee9e9
 */

cac_delete_pki_applet_private(VCardAppletPrivate *applet_private)

{

    CACPKIAppletData *pki_applet_data = NULL;



    if (applet_private == NULL) {

        return;

    }

    pki_applet_data = &(applet_private->u.pki_data);

    if (pki_applet_data->cert != NULL) {

        g_free(pki_applet_data->cert);

    }

    if (pki_applet_data->sign_buffer != NULL) {

        g_free(pki_applet_data->sign_buffer);

    }

    if (pki_applet_data->key != NULL) {

        vcard_emul_delete_key(pki_applet_data->key);

    }

    g_free(applet_private);

}
