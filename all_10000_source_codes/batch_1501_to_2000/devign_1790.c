/* 
 * Benchmark Sample ID : devign_1790
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=b3ce84fea466f3bca2ff85d158744f00c0f429bd
 */

void qdev_prop_set_globals_for_type(DeviceState *dev, const char *typename,

                                    Error **errp)

{

    GlobalProperty *prop;



    QTAILQ_FOREACH(prop, &global_props, next) {

        Error *err = NULL;



        if (strcmp(typename, prop->driver) != 0) {

            continue;

        }

        prop->not_used = false;

        object_property_parse(OBJECT(dev), prop->value, prop->property, &err);

        if (err != NULL) {

            error_propagate(errp, err);

            return;

        }

    }

}
