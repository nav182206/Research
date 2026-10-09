/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3522
 * Dataset Source      : Devign
 * Project Origin      : qemu
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c83c66c3b58893a4dc056e272822beb88fe9ec7f
 */

void stream_start(BlockDriverState *bs, BlockDriverState *base,

                  const char *base_id, BlockDriverCompletionFunc *cb,

                  void *opaque, Error **errp)

{

    StreamBlockJob *s;

    Coroutine *co;



    s = block_job_create(&stream_job_type, bs, cb, opaque, errp);

    if (!s) {

        return;

    }



    s->base = base;

    if (base_id) {

        pstrcpy(s->backing_file_id, sizeof(s->backing_file_id), base_id);

    }



    co = qemu_coroutine_create(stream_run);

    trace_stream_start(bs, base, s, co, opaque);

    qemu_coroutine_enter(co, s);

}
