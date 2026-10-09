/* 
 * Benchmark Sample ID : devign_6120
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=b45c03f585ea9bb1af76c73e82195418c294919d
 */

void stellaris_gamepad_init(int n, qemu_irq *irq, const int *keycode)

{

    gamepad_state *s;

    int i;



    s = (gamepad_state *)g_malloc0(sizeof (gamepad_state));

    s->buttons = (gamepad_button *)g_malloc0(n * sizeof (gamepad_button));

    for (i = 0; i < n; i++) {

        s->buttons[i].irq = irq[i];

        s->buttons[i].keycode = keycode[i];

    }

    s->num_buttons = n;

    qemu_add_kbd_event_handler(stellaris_gamepad_put_key, s);

    vmstate_register(NULL, -1, &vmstate_stellaris_gamepad, s);

}
