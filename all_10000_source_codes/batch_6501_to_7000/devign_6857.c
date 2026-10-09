/* 
 * Benchmark Sample ID : devign_6857
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5cb9b56acfc0b50acf7ccd2d044ab4991c47fdde
 */

static int print_uint64(DeviceState *dev, Property *prop, char *dest, size_t len)

{

    uint64_t *ptr = qdev_get_prop_ptr(dev, prop);

    return snprintf(dest, len, "%" PRIu64, *ptr);

}
