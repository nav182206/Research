/* 
 * Benchmark Sample ID : devign_2993
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=100f738850639a108d6767316ce4dcc1d1ea4ae4
 */

static void ics_base_realize(DeviceState *dev, Error **errp)

{

    ICSStateClass *icsc = ICS_BASE_GET_CLASS(dev);

    ICSState *ics = ICS_BASE(dev);

    Object *obj;

    Error *err = NULL;



    obj = object_property_get_link(OBJECT(dev), ICS_PROP_XICS, &err);

    if (!obj) {

        error_setg(errp, "%s: required link '" ICS_PROP_XICS "' not found: %s",

                   __func__, error_get_pretty(err));

        return;

    }

    ics->xics = XICS_FABRIC(obj);





    if (icsc->realize) {

        icsc->realize(dev, errp);

    }

}
