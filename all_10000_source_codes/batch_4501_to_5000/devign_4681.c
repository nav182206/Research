/* 
 * Benchmark Sample ID : devign_4681
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=04763c6f87690b31cfcd0d324cf36a451531dcd0
 */

static void await_reference_mb_row(const H264Context *const h, H264Picture *ref,

                                   int mb_y)

{

    int ref_field         = ref->reference - 1;

    int ref_field_picture = ref->field_picture;

    int ref_height        = 16 * h->mb_height >> ref_field_picture;



    if (!HAVE_THREADS || !(h->avctx->active_thread_type & FF_THREAD_FRAME))

        return;



    /* FIXME: It can be safe to access mb stuff

     * even if pixels aren't deblocked yet. */



    ff_thread_await_progress(&ref->tf,

                             FFMIN(16 * mb_y >> ref_field_picture,

                                   ref_height - 1),

                             ref_field_picture && ref_field);

}
