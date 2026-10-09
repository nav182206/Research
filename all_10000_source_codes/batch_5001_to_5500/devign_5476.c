/* 
 * Benchmark Sample ID : devign_5476
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=77cb0f5aafc8e6d0c6d3c339f381c9b7921648e0
 */

static void adb_register_types(void)

{

    type_register_static(&adb_bus_type_info);

    type_register_static(&adb_device_type_info);

    type_register_static(&adb_kbd_type_info);

    type_register_static(&adb_mouse_type_info);

}
