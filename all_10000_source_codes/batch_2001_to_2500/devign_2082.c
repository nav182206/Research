/* 
 * Benchmark Sample ID : devign_2082
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a8170e5e97ad17ca169c64ba87ae2f53850dab4c
 */

static CadenceTimerState *cadence_timer_from_addr(void *opaque,

                                        target_phys_addr_t offset)

{

    unsigned int index;

    CadenceTTCState *s = (CadenceTTCState *)opaque;



    index = (offset >> 2) % 3;



    return &s->timer[index];

}
