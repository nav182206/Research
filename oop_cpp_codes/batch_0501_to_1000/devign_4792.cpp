/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_4792
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4bc6a3e54e06c47b8e23bfa3d873fa2f42dfec02
 */

type_init(parallel_register_types)



static bool parallel_init(ISABus *bus, int index, CharDriverState *chr)

{

    DeviceState *dev;

    ISADevice *isadev;



    isadev = isa_try_create(bus, "isa-parallel");

    if (!isadev) {

        return false;

    }

    dev = DEVICE(isadev);

    qdev_prop_set_uint32(dev, "index", index);

    qdev_prop_set_chr(dev, "chardev", chr);

    if (qdev_init(dev) < 0) {

        return false;

    }

    return true;

}
