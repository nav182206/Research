/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2941
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=a72b41035cc4925922b4164b7453c9a5c2b7e630
 */

static int mxg_update_cache(AVFormatContext *s, unsigned int cache_size)

{

    MXGContext *mxg = s->priv_data;

    unsigned int current_pos = mxg->buffer_ptr - mxg->buffer;

    unsigned int soi_pos;

    int ret;



    /* reallocate internal buffer */

    if (current_pos > current_pos + cache_size)

        return AVERROR(ENOMEM);

    soi_pos = mxg->soi_ptr - mxg->buffer;

    mxg->buffer = av_fast_realloc(mxg->buffer, &mxg->buffer_size,

                                  current_pos + cache_size +

                                  FF_INPUT_BUFFER_PADDING_SIZE);

    if (!mxg->buffer)

        return AVERROR(ENOMEM);

    mxg->buffer_ptr = mxg->buffer + current_pos;

    if (mxg->soi_ptr) mxg->soi_ptr = mxg->buffer + soi_pos;



    /* get data */

    ret = avio_read(s->pb, mxg->buffer_ptr + mxg->cache_size,

                     cache_size - mxg->cache_size);

    if (ret < 0)

        return ret;



    mxg->cache_size += ret;



    return ret;

}
