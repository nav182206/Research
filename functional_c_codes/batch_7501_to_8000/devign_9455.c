/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9455
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=568c73a4783cd981e9aa6de4f15dcda7829643ad
 */

static void ps2_keyboard_event(DeviceState *dev, QemuConsole *src,

                               InputEvent *evt)

{

    PS2KbdState *s = (PS2KbdState *)dev;

    int scancodes[3], i, count;



    qemu_system_wakeup_request(QEMU_WAKEUP_REASON_OTHER);

    count = qemu_input_key_value_to_scancode(evt->key->key,

                                             evt->key->down,

                                             scancodes);

    for (i = 0; i < count; i++) {

        ps2_put_keycode(s, scancodes[i]);

    }

}
