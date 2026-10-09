/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9990
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=04001767728fd4ed8b4f9d2ebbb9f9a8c9a7be0d
 */

static int config(struct vf_instance *vf,

    int width, int height, int d_width, int d_height,

    unsigned int flags, unsigned int outfmt)

{

    switch (vf->priv->mode) {

    case 0:

    case 3:

        return ff_vf_next_config(vf,width,height*2,d_width,d_height*2,flags,outfmt);

    case 1:            /* odd frames */

    case 2:            /* even frames */

    case 4:            /* alternate frame (height-preserving) interlacing */

        return ff_vf_next_config(vf,width,height,d_width,d_height,flags,outfmt);

    }

    return 0;

}
