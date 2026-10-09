/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3005
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=e2dae1faa84ada5746ac2114de7eb68abd824131
 */

static int encode_nals(AVCodecContext *ctx, uint8_t *buf, int size,

                       x264_nal_t *nals, int nnal, int skip_sei)

{

    X264Context *x4 = ctx->priv_data;

    uint8_t *p = buf;

    int i;



    /* Write the SEI as part of the first frame. */

    if (x4->sei_size > 0 && nnal > 0) {

        if (x4->sei_size > size) {


            return -1;


        memcpy(p, x4->sei, x4->sei_size);

        p += x4->sei_size;

        x4->sei_size = 0;

        // why is x4->sei not freed?




    for (i = 0; i < nnal; i++){

        /* Don't put the SEI in extradata. */

        if (skip_sei && nals[i].i_type == NAL_SEI) {

            x4->sei_size = nals[i].i_payload;

            x4->sei      = av_malloc(x4->sei_size);

            memcpy(x4->sei, nals[i].p_payload, nals[i].i_payload);

            continue;







        memcpy(p, nals[i].p_payload, nals[i].i_payload);

        p += nals[i].i_payload;




    return p - buf;
