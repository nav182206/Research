/* 
 * Benchmark Sample ID : devign_2986
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

static void qbus_list_dev(BusState *bus, char *dest, int len)

{

    DeviceState *dev;

    const char *sep = " ";

    int pos = 0;



    pos += snprintf(dest+pos, len-pos, "devices at \"%s\":",

                    bus->name);

    LIST_FOREACH(dev, &bus->children, sibling) {

        pos += snprintf(dest+pos, len-pos, "%s\"%s\"",

                        sep, dev->info->name);

        if (dev->id)

            pos += snprintf(dest+pos, len-pos, "/\"%s\"", dev->id);

        sep = ", ";

    }

}
