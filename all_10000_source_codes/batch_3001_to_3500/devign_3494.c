/* 
 * Benchmark Sample ID : devign_3494
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9d4c0f4f0a71e74fd7e04d73620268484d693adf
 */

sPAPRDRConnector *spapr_dr_connector_new(Object *owner, const char *type,

                                         uint32_t id)

{

    sPAPRDRConnector *drc = SPAPR_DR_CONNECTOR(object_new(type));

    char *prop_name;



    drc->id = id;

    drc->owner = owner;

    prop_name = g_strdup_printf("dr-connector[%"PRIu32"]",

                                spapr_drc_index(drc));

    object_property_add_child(owner, prop_name, OBJECT(drc), NULL);

    object_property_set_bool(OBJECT(drc), true, "realized", NULL);

    g_free(prop_name);



    /* PCI slot always start in a USABLE state, and stay there */

    if (spapr_drc_type(drc) == SPAPR_DR_CONNECTOR_TYPE_PCI) {

        drc->allocation_state = SPAPR_DR_ALLOCATION_STATE_USABLE;

    }



    return drc;

}
