/* 
 * Benchmark Sample ID : devign_5825
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2e96f5278095d44f090a4d89507e62d27cccf3b9
 */

static inline uint64_t v4l2_get_pts(V4L2Buffer *avbuf)

{

    V4L2m2mContext *s = buf_to_m2mctx(avbuf);

    AVRational v4l2_timebase = { 1, USEC_PER_SEC };

    int64_t v4l2_pts;



    /* convert pts back to encoder timebase */

    v4l2_pts = avbuf->buf.timestamp.tv_sec * USEC_PER_SEC + avbuf->buf.timestamp.tv_usec;



    return av_rescale_q(v4l2_pts, v4l2_timebase, s->avctx->time_base);

}
