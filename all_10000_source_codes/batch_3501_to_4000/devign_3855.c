/* 
 * Benchmark Sample ID : devign_3855
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8daea510951dd309a44cea8de415c685c43851cf
 */

static void release_drive(Object *obj, const char *name, void *opaque)

{

    DeviceState *dev = DEVICE(obj);

    Property *prop = opaque;

    BlockBackend **ptr = qdev_get_prop_ptr(dev, prop);



    if (*ptr) {

        blk_detach_dev(*ptr, dev);

        blockdev_auto_del(*ptr);

    }

}
