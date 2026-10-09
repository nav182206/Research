/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6435
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e8dd1d9c396104f0fac4b39a701143df49df2a74
 */

static int netmap_can_send(void *opaque)

{

    NetmapState *s = opaque;



    return qemu_can_send_packet(&s->nc);

}
