/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6731
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=39355c3826f5d9a2eb1ce3dc9b4cdd68893769d6
 */

void qbus_create_inplace(BusState *bus, const char *typename,

                         DeviceState *parent, const char *name)

{

    object_initialize(bus, typename);

    qbus_realize(bus, parent, name);

}
