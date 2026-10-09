/* 
 * Benchmark Sample ID : devign_9662
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=10c4c98ab7dc18169b37b76f6ea5e60ebe65222b
 */

BusState *qbus_create(BusType type, size_t size,

                      DeviceState *parent, const char *name)

{

    BusState *bus;



    bus = qemu_mallocz(size);

    bus->type = type;

    bus->parent = parent;

    bus->name = qemu_strdup(name);

    LIST_INIT(&bus->children);

    if (parent) {

        LIST_INSERT_HEAD(&parent->child_bus, bus, sibling);

    }

    return bus;

}
