/* 
 * Benchmark Sample ID : devign_7930
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=675463d9b6b2c2b65a713a6d906aeebe9e6750ae
 */

ISADevice *isa_create(ISABus *bus, const char *name)

{

    DeviceState *dev;



    if (!bus) {

        hw_error("Tried to create isa device %s with no isa bus present.",

                 name);

    }

    dev = qdev_create(BUS(bus), name);

    return ISA_DEVICE(dev);

}
