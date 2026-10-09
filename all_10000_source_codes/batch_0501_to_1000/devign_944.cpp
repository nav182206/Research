/* 
 * Benchmark Sample ID : devign_944
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b1e749c02172583ca85bb3a964a9b39221f9ac39
 */

static gboolean gd_window_key_event(GtkWidget *widget, GdkEventKey *key, void *opaque)

{

    GtkDisplayState *s = opaque;

    GtkAccelGroupEntry *entries;

    guint n_entries = 0;

    gboolean propagate_accel = TRUE;

    gboolean handled = FALSE;



    entries = gtk_accel_group_query(s->accel_group, key->keyval,

                                    key->state, &n_entries);

    if (n_entries) {

        const char *quark = g_quark_to_string(entries[0].accel_path_quark);



        if (gd_is_grab_active(s) && strstart(quark, "<QEMU>/File/", NULL)) {

            propagate_accel = FALSE;

        }

    }



    if (!handled && propagate_accel) {

        handled = gtk_window_activate_key(GTK_WINDOW(widget), key);

    }

    if (handled) {

        gtk_release_modifiers(s);

    } else {

        handled = gtk_window_propagate_key_event(GTK_WINDOW(widget), key);

    }



    return handled;

}
