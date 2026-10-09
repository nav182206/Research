/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_2779
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c8389550dedc65892fba9c3df29423efd802f544
 */

static void vmgenid_device_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);



    dc->vmsd = &vmstate_vmgenid;

    dc->realize = vmgenid_realize;

    dc->hotpluggable = false;

    dc->props = vmgenid_properties;

    set_bit(DEVICE_CATEGORY_MISC, dc->categories);



    object_class_property_add_str(klass, VMGENID_GUID, NULL,

                                  vmgenid_set_guid, NULL);

    object_class_property_set_description(klass, VMGENID_GUID,

                                    "Set Global Unique Identifier "

                                    "(big-endian) or auto for random value",

                                    NULL);

}
