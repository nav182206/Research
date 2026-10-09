/* 
 * Benchmark Sample ID : devign_1457
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1a01716a307387e5cf1336f61a96f772dddadc90
 */

static gboolean gd_key_event(GtkWidget *widget, GdkEventKey *key, void *opaque)
{
    VirtualConsole *vc = opaque;
    GtkDisplayState *s = vc->s;
    int gdk_keycode = key->hardware_keycode;
    int qemu_keycode;
    int i;
    if (key->keyval == GDK_KEY_Pause) {
        qemu_input_event_send_key_qcode(vc->gfx.dcl.con, Q_KEY_CODE_PAUSE,
                                        key->type == GDK_KEY_PRESS);
    qemu_keycode = gd_map_keycode(s, gtk_widget_get_display(widget),
                                  gdk_keycode);
    trace_gd_key_event(vc->label, gdk_keycode, qemu_keycode,
                       (key->type == GDK_KEY_PRESS) ? "down" : "up");
    for (i = 0; i < ARRAY_SIZE(modifier_keycode); i++) {
        if (qemu_keycode == modifier_keycode[i]) {
            s->modifier_pressed[i] = (key->type == GDK_KEY_PRESS);
    qemu_input_event_send_key_number(vc->gfx.dcl.con, qemu_keycode,
                                     key->type == GDK_KEY_PRESS);
