/* 
 * Benchmark Sample ID : devign_4484
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

USBBus *usb_bus_new(DeviceState *host)

{

    USBBus *bus;



    bus = FROM_QBUS(USBBus, qbus_create(&usb_bus_info, host, NULL));

    bus->busnr = next_usb_bus++;

    TAILQ_INIT(&bus->free);

    TAILQ_INIT(&bus->used);

    TAILQ_INSERT_TAIL(&busses, bus, next);

    return bus;

}
