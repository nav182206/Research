/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7900
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=77cb0f5aafc8e6d0c6d3c339f381c9b7921648e0
 */

static void adb_kbd_initfn(Object *obj)

{

    ADBDevice *d = ADB_DEVICE(obj);



    d->devaddr = ADB_DEVID_KEYBOARD;

}
