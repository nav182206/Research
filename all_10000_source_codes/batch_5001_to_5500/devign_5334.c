/* 
 * Benchmark Sample ID : devign_5334
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3176217c60ca7828712985092d9102d331ea4f3d
 */

static int output_frame(H264Context *h, AVFrame *dst, AVFrame *src)

{

    int i;

    int ret = av_frame_ref(dst, src);

    if (ret < 0)

        return ret;



    if (!h->sps.crop)

        return 0;



    for (i = 0; i < 3; i++) {

        int hshift = (i > 0) ? h->chroma_x_shift : 0;

        int vshift = (i > 0) ? h->chroma_y_shift : 0;

        int off    = ((h->sps.crop_left >> hshift) << h->pixel_shift) +

                     (h->sps.crop_top >> vshift) * dst->linesize[i];

        dst->data[i] += off;

    }

    return 0;

}
