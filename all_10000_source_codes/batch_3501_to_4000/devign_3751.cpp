/* 
 * Benchmark Sample ID : devign_3751
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f6b5319d412cda360695e2005737f91ca8201af0
 */

static DeviceClass *qdev_get_device_class(const char **driver, Error **errp)

{

    ObjectClass *oc;

    DeviceClass *dc;



    oc = object_class_by_name(*driver);

    if (!oc) {

        const char *typename = find_typename_by_alias(*driver);



        if (typename) {

            *driver = typename;

            oc = object_class_by_name(*driver);

        }

    }



    if (!object_class_dynamic_cast(oc, TYPE_DEVICE)) {

        error_setg(errp, "'%s' is not a valid device model name", *driver);

        return NULL;

    }



    if (object_class_is_abstract(oc)) {

        error_setg(errp, QERR_INVALID_PARAMETER_VALUE, "driver",

                   "non-abstract device type");

        return NULL;

    }



    dc = DEVICE_CLASS(oc);

    if (dc->cannot_instantiate_with_device_add_yet ||

        (qdev_hotplug && !dc->hotpluggable)) {

        error_setg(errp, QERR_INVALID_PARAMETER_VALUE, "driver",

                   "pluggable device type");

        return NULL;

    }



    return dc;

}
