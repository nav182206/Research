/* 
 * Benchmark Sample ID : devign_1701
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=ee68697551cd81186c5b12eba10c158350cf1165
 */

void laio_attach_aio_context(LinuxAioState *s, AioContext *new_context)

{

    s->aio_context = new_context;

    s->completion_bh = aio_bh_new(new_context, qemu_laio_completion_bh, s);

    aio_set_event_notifier(new_context, &s->e, false,

                           qemu_laio_completion_cb, NULL);

}
