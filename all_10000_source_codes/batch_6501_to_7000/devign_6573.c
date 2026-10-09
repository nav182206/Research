/* 
 * Benchmark Sample ID : devign_6573
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=23f3f92361a3db53e595de33cfd5440f53bee220
 */

static int decode_dc_progressive(MJpegDecodeContext *s, int16_t *block,

                                 int component, int dc_index,

                                 int16_t *quant_matrix, int Al)

{

    int val;

    s->bdsp.clear_block(block);

    val = mjpeg_decode_dc(s, dc_index);

    if (val == 0xfffff) {

        av_log(s->avctx, AV_LOG_ERROR, "error dc\n");

        return AVERROR_INVALIDDATA;

    }

    val = (val * (quant_matrix[0] << Al)) + s->last_dc[component];

    s->last_dc[component] = val;

    block[0] = val;

    return 0;

}
