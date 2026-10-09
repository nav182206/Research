/* 
 * Benchmark Sample ID : devign_7495
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ab9de3692e34dc874ce44c7905590ef98445ce33
 */

static void logerr (struct audio_pt *pt, int err, const char *fmt, ...)

{

    va_list ap;



    va_start (ap, fmt);

    AUD_vlog (pt->drv, fmt, ap);

    va_end (ap);



    AUD_log (NULL, "\n");

    AUD_log (pt->drv, "Reason: %s\n", strerror (err));

}
