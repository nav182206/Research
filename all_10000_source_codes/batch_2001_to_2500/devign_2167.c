/* 
 * Benchmark Sample ID : devign_2167
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ad02b96ad86baf6dd72a43b04876b2d6ea957112
 */

void kbd_put_keycode(int keycode)

{

    if (!runstate_is_running()) {

        return;

    }

    if (qemu_put_kbd_event) {

        qemu_put_kbd_event(qemu_put_kbd_event_opaque, keycode);

    }

}
