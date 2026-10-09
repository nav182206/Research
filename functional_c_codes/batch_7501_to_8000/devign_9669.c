/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9669
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=1197cbb9eda1dc82e2fa1815ca62bc3de158353e
 */

static int print_size(DeviceState *dev, Property *prop, char *dest, size_t len)

{

    uint64_t *ptr = qdev_get_prop_ptr(dev, prop);

    char suffixes[] = {'T', 'G', 'M', 'K', 'B'};

    int i = 0;

    uint64_t div;



    for (div = 1ULL << 40; !(*ptr / div) ; div >>= 10) {

        i++;

    }

    return snprintf(dest, len, "%0.03f%c", (double)*ptr/div, suffixes[i]);

}
