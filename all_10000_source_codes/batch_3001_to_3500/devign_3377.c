/* 
 * Benchmark Sample ID : devign_3377
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f9a8b5530d438f836f9697639814f585aaec554d
 */

static void qdev_prop_set_globals_for_type(DeviceState *dev,

                                const char *typename)

{

    GlobalProperty *prop;



    QTAILQ_FOREACH(prop, &global_props, next) {

        Error *err = NULL;



        if (strcmp(typename, prop->driver) != 0) {

            continue;

        }

        prop->used = true;

        object_property_parse(OBJECT(dev), prop->value, prop->property, &err);

        if (err != NULL) {

            assert(prop->user_provided);

            error_reportf_err(err, "Warning: global %s.%s=%s ignored: ",

                              prop->driver, prop->property, prop->value);

            return;

        }

    }

}
