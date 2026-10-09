/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7241
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9d4c0f4f0a71e74fd7e04d73620268484d693adf
 */

void spapr_drc_attach(sPAPRDRConnector *drc, DeviceState *d, void *fdt,

                      int fdt_start_offset, Error **errp)

{

    trace_spapr_drc_attach(spapr_drc_index(drc));



    if (drc->isolation_state != SPAPR_DR_ISOLATION_STATE_ISOLATED) {

        error_setg(errp, "an attached device is still awaiting release");

        return;

    }

    if (spapr_drc_type(drc) == SPAPR_DR_CONNECTOR_TYPE_PCI) {

        g_assert(drc->allocation_state == SPAPR_DR_ALLOCATION_STATE_USABLE);

    }

    g_assert(fdt);



    drc->dev = d;

    drc->fdt = fdt;

    drc->fdt_start_offset = fdt_start_offset;



    object_property_add_link(OBJECT(drc), "device",

                             object_get_typename(OBJECT(drc->dev)),

                             (Object **)(&drc->dev),

                             NULL, 0, NULL);

}
