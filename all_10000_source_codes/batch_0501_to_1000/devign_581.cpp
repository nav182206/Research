/* 
 * Benchmark Sample ID : devign_581
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e4f4fb1eca795e36f363b4647724221e774523c1
 */

static void sdhci_sysbus_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);



    dc->vmsd = &sdhci_vmstate;

    dc->props = sdhci_sysbus_properties;

    dc->realize = sdhci_sysbus_realize;

    dc->reset = sdhci_poweron_reset;






}
