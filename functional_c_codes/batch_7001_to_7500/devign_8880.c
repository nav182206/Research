/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8880
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=5cb9b56acfc0b50acf7ccd2d044ab4991c47fdde
 */

static int parse_vlan(DeviceState *dev, Property *prop, const char *str)

{

    VLANState **ptr = qdev_get_prop_ptr(dev, prop);

    int id;



    if (sscanf(str, "%d", &id) != 1)

        return -EINVAL;

    *ptr = qemu_find_vlan(id, 1);

    if (*ptr == NULL)

        return -ENOENT;

    return 0;

}
