/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3454
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=500220a8e84acb952e8a62d88505c5fb6a51843a
 */

static int mimic_decode_update_thread_context(AVCodecContext *avctx, const AVCodecContext *avctx_from)

{

    MimicContext *dst = avctx->priv_data, *src = avctx_from->priv_data;

    int i, ret;



    if (avctx == avctx_from)

        return 0;



    dst->cur_index  = src->next_cur_index;

    dst->prev_index = src->next_prev_index;



    memcpy(dst->flipped_ptrs, src->flipped_ptrs, sizeof(src->flipped_ptrs));



    for (i = 0; i < FF_ARRAY_ELEMS(dst->frames); i++) {

        ff_thread_release_buffer(avctx, &dst->frames[i]);

        if (src->frames[i].f->data[0]) {

            ret = ff_thread_ref_frame(&dst->frames[i], &src->frames[i]);

            if (ret < 0)

                return ret;

        }

    }



    return 0;

}
