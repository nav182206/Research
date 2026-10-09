/* 
 * Benchmark Sample ID : devign_2846
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=449041d4db1f82f281fe097e832f07cd9ee1e864
 */

static int parse_hex32(DeviceState *dev, Property *prop, const char *str)

{

    uint32_t *ptr = qdev_get_prop_ptr(dev, prop);



    if (sscanf(str, "%" PRIx32, ptr) != 1)

        return -EINVAL;

    return 0;

}
