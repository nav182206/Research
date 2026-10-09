/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3079
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=10c4c98ab7dc18169b37b76f6ea5e60ebe65222b
 */

static void qbus_print(Monitor *mon, BusState *bus, int indent)

{

    struct DeviceState *dev;



    qdev_printf("bus: %s\n", bus->name);

    indent += 2;

    qdev_printf("type %s\n", bus_type_names[bus->type]);

    LIST_FOREACH(dev, &bus->children, sibling) {

        qdev_print(mon, dev, indent);

    }

}
