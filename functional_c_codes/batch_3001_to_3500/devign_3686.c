/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3686
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=8c55ff393340998faae887dfac19e7ef128e1e58
 */

static int output_frame(H264Context *h, AVFrame *dst, Picture *srcp)

{

    AVFrame *src = &srcp->f;

    int i;

    int ret = av_frame_ref(dst, src);

    if (ret < 0)

        return ret;



    av_dict_set(&dst->metadata, "stereo_mode", ff_h264_sei_stereo_mode(h), 0);



    if (!srcp->crop)

        return 0;



    for (i = 0; i < 3; i++) {

        int hshift = (i > 0) ? h->chroma_x_shift : 0;

        int vshift = (i > 0) ? h->chroma_y_shift : 0;

        int off    = ((srcp->crop_left >> hshift) << h->pixel_shift) +

                      (srcp->crop_top  >> vshift) * dst->linesize[i];

        dst->data[i] += off;

    }

    return 0;

}
