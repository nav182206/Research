/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2363
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2ed1ebcf65edf6757d8904000889ce52cc0a9d1b
 */

int qemu_timedate_diff(struct tm *tm)

{

    time_t seconds;



    if (rtc_date_offset == -1)

        if (rtc_utc)

            seconds = mktimegm(tm);

        else {

            struct tm tmp = *tm;

            tmp.tm_isdst = -1; /* use timezone to figure it out */

            seconds = mktime(&tmp);

	}

    else

        seconds = mktimegm(tm) + rtc_date_offset;



    return seconds - time(NULL);

}
