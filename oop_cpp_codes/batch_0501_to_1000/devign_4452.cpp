/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_4452
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e4f4fb1eca795e36f363b4647724221e774523c1
 */

static void xen_sysdev_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);

    SysBusDeviceClass *k = SYS_BUS_DEVICE_CLASS(klass);



    k->init = xen_sysdev_init;

    dc->props = xen_sysdev_properties;

    dc->bus_type = TYPE_XENSYSBUS;






}
