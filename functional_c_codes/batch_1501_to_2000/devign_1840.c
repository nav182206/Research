/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_1840
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=449041d4db1f82f281fe097e832f07cd9ee1e864
 */

static int parse_uint32(DeviceState *dev, Property *prop, const char *str)

{

    uint32_t *ptr = qdev_get_prop_ptr(dev, prop);

    const char *fmt;



    /* accept both hex and decimal */

    fmt = strncasecmp(str, "0x",2) == 0 ? "%" PRIx32 : "%" PRIu32;

    if (sscanf(str, fmt, ptr) != 1)

        return -EINVAL;

    return 0;

}
