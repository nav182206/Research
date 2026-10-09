/* 
 * Benchmark Sample ID : devign_2789
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3f66aa9c07d6392757f9d7b83849c7f791981725
 */

ISADevice *isa_create(const char *name)

{

    DeviceState *dev;



    if (!isabus) {

        fprintf(stderr, "Tried to create isa device %s with no isa bus present.\n", name);

        return NULL;

    }

    dev = qdev_create(&isabus->qbus, name);

    return DO_UPCAST(ISADevice, qdev, dev);

}
