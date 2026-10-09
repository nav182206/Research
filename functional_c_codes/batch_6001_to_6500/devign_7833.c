/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7833
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=defdb20e1a8ac3a7200aaf190d7fb20a5ac8bcea
 */

ParallelState *parallel_init(int index, CharDriverState *chr)

{

    ISADevice *dev;



    dev = isa_create("isa-parallel");

    qdev_prop_set_uint32(&dev->qdev, "index", index);

    qdev_prop_set_chr(&dev->qdev, "chardev", chr);

    if (qdev_init(&dev->qdev) < 0)

        return NULL;

    return &DO_UPCAST(ISAParallelState, dev, dev)->state;

}
