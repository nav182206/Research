/* 
 * Benchmark Sample ID : devign_6336
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=2f11aa141a01f97c5d2a015bd9dbdb27314b79c4
 */

static int config(struct vf_instance *vf,

                  int width, int height, int d_width, int d_height,

                  unsigned int flags, unsigned int outfmt)

{

        /* FIXME - also support UYVY output? */

        return ff_vf_next_config(vf, width * vf->priv->scalew,

                              height / vf->priv->scaleh - vf->priv->skipline, d_width, d_height, flags, IMGFMT_YV12);

}
