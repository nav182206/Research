/* 
 * Benchmark Sample ID : devign_8353
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a553c6a347d3d28d7ee44c3df3d5c4ee780dba23
 */

static void unref_picture(H264Context *h, Picture *pic)

{

    int off = offsetof(Picture, tf) + sizeof(pic->tf);

    int i;



    if (!pic->f.data[0])

        return;



    ff_thread_release_buffer(h->avctx, &pic->tf);

    av_buffer_unref(&pic->hwaccel_priv_buf);



    av_buffer_unref(&pic->qscale_table_buf);

    av_buffer_unref(&pic->mb_type_buf);

    for (i = 0; i < 2; i++) {

        av_buffer_unref(&pic->motion_val_buf[i]);

        av_buffer_unref(&pic->ref_index_buf[i]);

    }



    memset((uint8_t*)pic + off, 0, sizeof(*pic) - off);

}
