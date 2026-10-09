/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6675
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=26022652c6fd067b9fa09280f5a6d6284a21c73f
 */

void usb_wakeup(USBEndpoint *ep, unsigned int stream)

{

    USBDevice *dev = ep->dev;

    USBBus *bus = usb_bus_from_device(dev);











    if (dev->remote_wakeup && dev->port && dev->port->ops->wakeup) {

        dev->port->ops->wakeup(dev->port);


    if (bus->ops->wakeup_endpoint) {

        bus->ops->wakeup_endpoint(bus, ep, stream);
