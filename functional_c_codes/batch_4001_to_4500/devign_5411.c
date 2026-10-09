/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5411
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=82a41186941c419afde977f477f19c545b40c1c5
 */

static void iothread_set_poll_max_ns(Object *obj, Visitor *v,

        const char *name, void *opaque, Error **errp)

{

    IOThread *iothread = IOTHREAD(obj);

    Error *local_err = NULL;

    int64_t value;



    visit_type_int64(v, name, &value, &local_err);

    if (local_err) {

        goto out;

    }



    if (value < 0) {

        error_setg(&local_err, "poll_max_ns value must be in range "

                   "[0, %"PRId64"]", INT64_MAX);

        goto out;

    }



    iothread->poll_max_ns = value;



    if (iothread->ctx) {

        aio_context_set_poll_params(iothread->ctx, value, &local_err);

    }



out:

    error_propagate(errp, local_err);

}
