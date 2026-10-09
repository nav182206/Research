/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_9871
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1687a089f103f9b7a1b4a1555068054cb46ee9e9
 */

vcard_free(VCard *vcard)

{

    VCardApplet *current_applet = NULL;

    VCardApplet *next_applet = NULL;



    if (vcard == NULL) {

        return;

    }

    vcard->reference_count--;

    if (vcard->reference_count != 0) {

        return;

    }

    if (vcard->vcard_private_free) {

        (*vcard->vcard_private_free)(vcard->vcard_private);

        vcard->vcard_private_free = 0;

        vcard->vcard_private = 0;

    }

    for (current_applet = vcard->applet_list; current_applet;

                                        current_applet = next_applet) {

        next_applet = current_applet->next;

        vcard_delete_applet(current_applet);

    }

    vcard_buffer_response_delete(vcard->vcard_buffer_response);

    g_free(vcard);

}
