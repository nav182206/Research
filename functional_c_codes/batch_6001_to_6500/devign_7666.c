/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7666
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=210b580b106fa798149e28aa13c66b325a43204e
 */

static void rtas_set_time_of_day(sPAPREnvironment *spapr,

                                 uint32_t token, uint32_t nargs,

                                 target_ulong args,

                                 uint32_t nret, target_ulong rets)

{

    struct tm tm;



    tm.tm_year = rtas_ld(args, 0) - 1900;

    tm.tm_mon = rtas_ld(args, 1) - 1;

    tm.tm_mday = rtas_ld(args, 2);

    tm.tm_hour = rtas_ld(args, 3);

    tm.tm_min = rtas_ld(args, 4);

    tm.tm_sec = rtas_ld(args, 5);



    /* Just generate a monitor event for the change */

    rtc_change_mon_event(&tm);

    spapr->rtc_offset = qemu_timedate_diff(&tm);



    rtas_st(rets, 0, 0); /* Success */

}
