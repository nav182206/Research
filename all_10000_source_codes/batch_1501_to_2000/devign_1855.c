/* 
 * Benchmark Sample ID : devign_1855
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=27bb0b2d6f80f058bdb6fcc8fcdfa69b0c8a6d71
 */

static uint32_t timer_int_route(struct HPETTimer *timer)

{

    uint32_t route;

    route = (timer->config & HPET_TN_INT_ROUTE_MASK) >> HPET_TN_INT_ROUTE_SHIFT;

    return route;

}
