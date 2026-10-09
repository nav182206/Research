/* 
 * Benchmark Sample ID : devign_8333
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2884cf5b934808f547b5268a51be631805c25857
 */

static gboolean gd_leave_event(GtkWidget *widget, GdkEventCrossing *crossing,

                               gpointer opaque)

{

    VirtualConsole *vc = opaque;

    GtkDisplayState *s = vc->s;



    if (!gd_is_grab_active(s) && gd_grab_on_hover(s)) {

        gd_ungrab_keyboard(s);

    }



    return TRUE;

}
