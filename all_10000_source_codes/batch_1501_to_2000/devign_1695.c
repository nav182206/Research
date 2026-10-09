/* 
 * Benchmark Sample ID : devign_1695
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=72cf2d4f0e181d0d3a3122e04129c58a95da713e
 */

static BusState *qbus_find_recursive(BusState *bus, const char *name,

                                     const BusInfo *info)

{

    DeviceState *dev;

    BusState *child, *ret;

    int match = 1;



    if (name && (strcmp(bus->name, name) != 0)) {

        match = 0;

    }

    if (info && (bus->info != info)) {

        match = 0;

    }

    if (match) {

        return bus;

    }



    LIST_FOREACH(dev, &bus->children, sibling) {

        LIST_FOREACH(child, &dev->child_bus, sibling) {

            ret = qbus_find_recursive(child, name, info);

            if (ret) {

                return ret;

            }

        }

    }

    return NULL;

}
