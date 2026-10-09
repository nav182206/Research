/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5214
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=77cb0f5aafc8e6d0c6d3c339f381c9b7921648e0
 */

static void adb_kbd_realizefn(DeviceState *dev, Error **errp)

{

    ADBKeyboardClass *akc = ADB_KEYBOARD_GET_CLASS(dev);

    akc->parent_realize(dev, errp);

    qemu_input_handler_register(dev, &adb_keyboard_handler);

}
