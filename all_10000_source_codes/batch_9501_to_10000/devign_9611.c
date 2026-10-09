/* 
 * Benchmark Sample ID : devign_9611
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9be385980d37e8f4fd33f605f5fb1c3d144170a8
 */

static uint64_t get_guest_rtc_ns(RTCState *s)

{

    uint64_t guest_rtc;

    uint64_t guest_clock = qemu_clock_get_ns(rtc_clock);



    guest_rtc = s->base_rtc * NANOSECONDS_PER_SECOND +

        guest_clock - s->last_update + s->offset;

    return guest_rtc;

}
