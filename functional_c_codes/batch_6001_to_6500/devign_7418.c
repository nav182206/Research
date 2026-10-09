/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7418
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=2cc51d5025c976aa268a854df1eec86014512c8c
 */

int ff_v4l2_context_set_status(V4L2Context* ctx, int cmd)

{

    int type = ctx->type;

    int ret;



    ret = ioctl(ctx_to_m2mctx(ctx)->fd, cmd, &type);

    if (ret < 0)

        return AVERROR(errno);



    ctx->streamon = (cmd == VIDIOC_STREAMON);



    return 0;

}
