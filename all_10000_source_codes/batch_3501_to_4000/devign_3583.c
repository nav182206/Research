/* 
 * Benchmark Sample ID : devign_3583
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=32bafa8fdd098d52fbf1102d5a5e48d29398c0aa
 */

void qemu_input_event_send_key_number(QemuConsole *src, int num, bool down)

{

    KeyValue *key = g_new0(KeyValue, 1);

    key->type = KEY_VALUE_KIND_NUMBER;

    key->u.number = num;

    qemu_input_event_send_key(src, key, down);

}
