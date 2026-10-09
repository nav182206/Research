/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7554
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5104a1f65088285ddf870aa641b9061064e8757d
 */

static void gd_update_caption(GtkDisplayState *s)

{

    const char *status = "";

    gchar *title;



    if (!runstate_is_running()) {

        status = " [Stopped]";

    }



    if (qemu_name) {

        title = g_strdup_printf("QEMU (%s)%s", qemu_name, status);

    } else {

        title = g_strdup_printf("QEMU%s", status);

    }



    gtk_window_set_title(GTK_WINDOW(s->window), title);



    g_free(title);

}
