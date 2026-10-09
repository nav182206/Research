/* 
 * Benchmark Sample ID : devign_9400
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=c43485f70765cb488bfdf95dc783bb9b14eb1179
 */

static int decode_hq_slice_row(AVCodecContext *avctx, void *arg, int jobnr, int threadnr)

{

    int i;

    DiracContext *s = avctx->priv_data;

    DiracSlice *slices = ((DiracSlice *)arg) + s->num_x*jobnr;

    for (i = 0; i < s->num_x; i++)

        decode_hq_slice(avctx, &slices[i]);

    return 0;

}
