/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7455
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=faabdbb792889bf011a593578d1de51e14616bb7
 */

void qdev_property_add_static(DeviceState *dev, Property *prop,

                              Error **errp)

{

    Error *local_err = NULL;

    Object *obj = OBJECT(dev);



    /*

     * TODO qdev_prop_ptr does not have getters or setters.  It must

     * go now that it can be replaced with links.  The test should be

     * removed along with it: all static properties are read/write.

     */

    if (!prop->info->get && !prop->info->set) {

        return;

    }



    object_property_add(obj, prop->name, prop->info->name,

                        prop->info->get, prop->info->set,

                        prop->info->release,

                        prop, &local_err);



    if (local_err) {

        error_propagate(errp, local_err);

        return;

    }



    object_property_set_description(obj, prop->name,

                                    prop->info->description,

                                    &error_abort);



    if (prop->info->set_default_value) {

        prop->info->set_default_value(obj, prop);

    }

}
