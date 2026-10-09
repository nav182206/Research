/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9336
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=9ef91a677110ec200d7b2904fc4bcae5a77329ad
 */

static int posix_aio_flush(void *opaque)

{

    PosixAioState *s = opaque;

    return !!s->first_aio;

}
