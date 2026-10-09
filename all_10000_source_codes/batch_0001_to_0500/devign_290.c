/* 
 * Benchmark Sample ID : devign_290
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e23a1b33b53d25510320b26d9f154e19c6c99725
 */

DeviceState *ssi_create_slave(SSIBus *bus, const char *name)

{

    DeviceState *dev;

    dev = qdev_create(&bus->qbus, name);

    qdev_init(dev);

    return dev;

}
