/* 
 * Benchmark Sample ID : devign_4419
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : OOP_Cpp
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f6102c329c43d7d5e0bee1fc2fe4043e05f9810c
 */

static void init_event_facility_class(ObjectClass *klass, void *data)

{

    SysBusDeviceClass *sbdc = SYS_BUS_DEVICE_CLASS(klass);

    DeviceClass *dc = DEVICE_CLASS(sbdc);

    SCLPEventFacilityClass *k = EVENT_FACILITY_CLASS(dc);



    dc->reset = reset_event_facility;

    dc->vmsd = &vmstate_event_facility;

    set_bit(DEVICE_CATEGORY_MISC, dc->categories);

    k->init = init_event_facility;

    k->command_handler = command_handler;

    k->event_pending = event_pending;

}
