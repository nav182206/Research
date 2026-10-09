/* 
 * Benchmark Sample ID : devign_2421
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f9a8b5530d438f836f9697639814f585aaec554d
 */

int qdev_prop_check_globals(void)

{

    GlobalProperty *prop;

    int ret = 0;



    QTAILQ_FOREACH(prop, &global_props, next) {

        ObjectClass *oc;

        DeviceClass *dc;

        if (prop->used) {

            continue;

        }

        if (!prop->user_provided) {

            continue;

        }

        oc = object_class_by_name(prop->driver);

        oc = object_class_dynamic_cast(oc, TYPE_DEVICE);

        if (!oc) {

            error_report("Warning: global %s.%s has invalid class name",

                       prop->driver, prop->property);

            ret = 1;

            continue;

        }

        dc = DEVICE_CLASS(oc);

        if (!dc->hotpluggable && !prop->used) {

            error_report("Warning: global %s.%s=%s not used",

                       prop->driver, prop->property, prop->value);

            ret = 1;

            continue;

        }

    }

    return ret;

}
