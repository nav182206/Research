/* 
 * Benchmark Sample ID : devign_9843
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e13e973eedba0a52b4b8b079c4b85cdc68b7b4f0
 */

static CCIDBus *ccid_bus_new(DeviceState *dev)

{

    CCIDBus *bus;



    bus = FROM_QBUS(CCIDBus, qbus_create(&ccid_bus_info, dev, NULL));

    bus->qbus.allow_hotplug = 1;



    return bus;

}
