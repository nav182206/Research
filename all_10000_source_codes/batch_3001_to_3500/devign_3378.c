/* 
 * Benchmark Sample ID : devign_3378
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=5a0f6b099f3e8fcb95a80e3ffe52b3bf369efe24
 */

static unsigned char get_ref_idx(AVFrame *frame)

{

    FrameDecodeData *fdd;

    NVDECFrame *cf;



    if (!frame || !frame->private_ref)

        return 255;



    fdd = (FrameDecodeData*)frame->private_ref->data;

    cf  = (NVDECFrame*)fdd->hwaccel_priv;



    return cf->idx;

}
