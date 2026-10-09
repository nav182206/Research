/* 
 * Benchmark Sample ID : devign_6512
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f53c398aa603cea135ee58fd15249aeff7b9c7ea
 */

void usb_cancel_packet(USBPacket * p)

{

    assert(p->owner != NULL);

    usb_device_cancel_packet(p->owner->dev, p);

    p->owner = NULL;

}
