/* 
 * Benchmark Sample ID : devign_1026
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=7a7aae21ccab06606cee9aba846d2e30cb616763
 */

void qdev_prop_set_ptr(DeviceState *dev, const char *name, void *value)

{

    qdev_prop_set(dev, name, &value, PROP_TYPE_PTR);

}
