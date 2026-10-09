/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_8005
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ba3186c4e473963ba83b5792f3d02d4ac0a76ba5
 */

static void curl_multi_read(void *arg)

{

    CURLState *s = (CURLState *)arg;



    aio_context_acquire(s->s->aio_context);

    curl_multi_do_locked(s);

    curl_multi_check_completion(s->s);

    aio_context_release(s->s->aio_context);

}
