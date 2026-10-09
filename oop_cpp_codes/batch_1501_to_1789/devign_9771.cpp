/* 
 * Paradigm            : OOP_Cpp
 * Benchmark Sample ID : devign_9771
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8ccccff9dd7ba24c7a78861172e8dc6b07f1c392
 */

static void spapr_rtc_class_init(ObjectClass *oc, void *data)

{

    DeviceClass *dc = DEVICE_CLASS(oc);



    dc->realize = spapr_rtc_realize;

    dc->vmsd = &vmstate_spapr_rtc;





    spapr_rtas_register(RTAS_GET_TIME_OF_DAY, "get-time-of-day",

                        rtas_get_time_of_day);

    spapr_rtas_register(RTAS_SET_TIME_OF_DAY, "set-time-of-day",

                        rtas_set_time_of_day);

}
