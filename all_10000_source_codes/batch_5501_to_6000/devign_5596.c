/* 
 * Benchmark Sample ID : devign_5596
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5cb9b56acfc0b50acf7ccd2d044ab4991c47fdde
 */

static int parse_bit(DeviceState *dev, Property *prop, const char *str)

{

    if (!strcasecmp(str, "on"))

        bit_prop_set(dev, prop, true);

    else if (!strcasecmp(str, "off"))

        bit_prop_set(dev, prop, false);

    else

        return -EINVAL;

    return 0;

}
