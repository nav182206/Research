/* 
 * Benchmark Sample ID : devign_2647
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5cb9b56acfc0b50acf7ccd2d044ab4991c47fdde
 */

static int parse_int32(DeviceState *dev, Property *prop, const char *str)

{

    int32_t *ptr = qdev_get_prop_ptr(dev, prop);

    char *end;



    *ptr = strtol(str, &end, 10);

    if ((*end != '\0') || (end == str)) {

        return -EINVAL;

    }



    return 0;

}
