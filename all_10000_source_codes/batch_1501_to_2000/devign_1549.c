/* 
 * Benchmark Sample ID : devign_1549
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=036f7166c73a9e0cc1b2f10c03763e61894a1033
 */

static int print_ptr(DeviceState *dev, Property *prop, char *dest, size_t len)

{

    void **ptr = qdev_get_prop_ptr(dev, prop);

    return snprintf(dest, len, "<%p>", *ptr);

}
