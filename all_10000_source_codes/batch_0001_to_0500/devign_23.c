/* 
 * Benchmark Sample ID : devign_23
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=fe0f4e56577a2dbd373bb50b0ae2d49e69d822fc
 */

int av_packet_ref(AVPacket *dst, AVPacket *src)

{

    int ret;



    ret = av_packet_copy_props(dst, src);

    if (ret < 0)

        return ret;



    if (!src->buf) {

        ret = packet_alloc(&dst->buf, src->size);

        if (ret < 0)

            goto fail;

        memcpy(dst->buf->data, src->data, src->size);

    } else

        dst->buf = av_buffer_ref(src->buf);



    dst->size = src->size;

    dst->data = dst->buf->data;

    return 0;

fail:

    av_packet_free_side_data(dst);

    return ret;

}
