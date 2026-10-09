/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6574
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=3ba35a346cd2ee86fff83a0d0534e8a2265984fd
 */

static int config_input(AVFilterLink *inlink)
{
    HQDN3DContext *s = inlink->dst->priv;
    const AVPixFmtDescriptor *desc = av_pix_fmt_desc_get(inlink->format);
    int i;
    s->hsub  = desc->log2_chroma_w;
    s->vsub  = desc->log2_chroma_h;
    s->depth = desc->comp[0].depth_minus1+1;
    s->line = av_malloc(inlink->w * sizeof(*s->line));
    if (!s->line)
        return AVERROR(ENOMEM);
    for (i = 0; i < 4; i++) {
        s->coefs[i] = precalc_coefs(s->strength[i], s->depth);
        if (!s->coefs[i])
            return AVERROR(ENOMEM);
    }
    if (ARCH_X86)
        ff_hqdn3d_init_x86(s);
    return 0;
}
