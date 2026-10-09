/* 
 * Benchmark Sample ID : devign_1117
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=800b0e814bef7cd14ae2bce149c09d70676e93fb
 */

static void gd_mouse_mode_change(Notifier *notify, void *data)

{

    gd_update_cursor(container_of(notify, GtkDisplayState, mouse_mode_notifier),

                     FALSE);

}
