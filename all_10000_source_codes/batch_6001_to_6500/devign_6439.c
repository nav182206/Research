/* 
 * Benchmark Sample ID : devign_6439
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=949fc82314cc84162e64a5323764527a542421ce
 */

static int print_bit(DeviceState *dev, Property *prop, char *dest, size_t len)

{

    uint32_t *p = qdev_get_prop_ptr(dev, prop);

    return snprintf(dest, len, (*p & qdev_get_prop_mask(prop)) ? "on" : "off");

}
