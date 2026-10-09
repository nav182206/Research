/* 
 * Benchmark Sample ID : devign_3134
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=cf864569cd9134ee503ad9eb6be2881001c0ed80
 */

int vnc_display_password(DisplayState *ds, const char *password)

{

    VncDisplay *vs = vnc_display;



    if (!vs) {

        return -EINVAL;

    }



    if (!password) {

        /* This is not the intention of this interface but err on the side

           of being safe */

        return vnc_display_disable_login(ds);

    }



    if (vs->password) {

        g_free(vs->password);

        vs->password = NULL;

    }

    vs->password = g_strdup(password);

    if (vs->auth == VNC_AUTH_NONE) {

        vs->auth = VNC_AUTH_VNC;

    }



    return 0;

}
