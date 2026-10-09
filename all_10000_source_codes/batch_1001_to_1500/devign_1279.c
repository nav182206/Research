/* 
 * Benchmark Sample ID : devign_1279
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e23a1b33b53d25510320b26d9f154e19c6c99725
 */

ISABus *isa_bus_new(DeviceState *dev)

{

    if (isabus) {

        fprintf(stderr, "Can't create a second ISA bus\n");

        return NULL;

    }

    if (NULL == dev) {

        dev = qdev_create(NULL, "isabus-bridge");

        qdev_init(dev);

    }



    isabus = FROM_QBUS(ISABus, qbus_create(&isa_bus_info, dev, NULL));

    return isabus;

}
