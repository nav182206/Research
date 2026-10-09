/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2275
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f6774f905fb3cfdc319523ac640be30b14c1bc55
 */

int ff_mpeg_ref_picture(MpegEncContext *s, Picture *dst, Picture *src)

{

    int ret;



    av_assert0(!dst->f.buf[0]);

    av_assert0(src->f.buf[0]);



    src->tf.f = &src->f;

    dst->tf.f = &dst->f;

    ret = ff_thread_ref_frame(&dst->tf, &src->tf);

    if (ret < 0)

        goto fail;



    ret = update_picture_tables(dst, src);

    if (ret < 0)

        goto fail;



    if (src->hwaccel_picture_private) {

        dst->hwaccel_priv_buf = av_buffer_ref(src->hwaccel_priv_buf);

        if (!dst->hwaccel_priv_buf)

            goto fail;

        dst->hwaccel_picture_private = dst->hwaccel_priv_buf->data;

    }



    dst->field_picture           = src->field_picture;

    dst->mb_var_sum              = src->mb_var_sum;

    dst->mc_mb_var_sum           = src->mc_mb_var_sum;

    dst->b_frame_score           = src->b_frame_score;

    dst->needs_realloc           = src->needs_realloc;

    dst->reference               = src->reference;

    dst->shared                  = src->shared;



    return 0;

fail:

    ff_mpeg_unref_picture(s, dst);

    return ret;

}
