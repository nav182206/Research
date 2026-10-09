/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_5204
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=efec3dd631d94160288392721a5f9c39e50fb2bc
 */

static void pl110_class_init(ObjectClass *klass, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(klass);

    SysBusDeviceClass *k = SYS_BUS_DEVICE_CLASS(klass);



    k->init = pl110_initfn;

    set_bit(DEVICE_CATEGORY_DISPLAY, dc->categories);

    dc->no_user = 1;

    dc->vmsd = &vmstate_pl110;

}
