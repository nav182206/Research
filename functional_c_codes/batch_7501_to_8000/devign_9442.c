/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9442
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=731d5856cbb9c160fe02b90cd3cf354ea4f52f34
 */

static void net_dump_cleanup(VLANClientState *vc)

{

    DumpState *s = vc->opaque;



    close(s->fd);

    qemu_free(s);

}
