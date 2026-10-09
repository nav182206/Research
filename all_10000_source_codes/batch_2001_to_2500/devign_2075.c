/* 
 * Benchmark Sample ID : devign_2075
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f0c9d64a68b776374ec4732424a3e27753ce37b6
 */

static void *acpi_set_bsel(PCIBus *bus, void *opaque)

{

    unsigned *bsel_alloc = opaque;

    unsigned *bus_bsel;



    if (qbus_is_hotpluggable(BUS(bus))) {

        bus_bsel = g_malloc(sizeof *bus_bsel);



        *bus_bsel = (*bsel_alloc)++;

        object_property_add_uint32_ptr(OBJECT(bus), ACPI_PCIHP_PROP_BSEL,

                                       bus_bsel, NULL);

    }



    return bsel_alloc;

}
