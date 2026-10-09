/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9535
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=1c02a9732aa2e5ec0eaf83e65044704af05e8400
 */

static void wmv2_add_block(Wmv2Context *w, DCTELEM *block1, uint8_t *dst, int stride, int n){

    MpegEncContext * const s= &w->s;



    switch(w->abt_type_table[n]){

    case 0:

        if (s->block_last_index[n] >= 0) {

            s->dsp.idct_add (dst, stride, block1);

        }

        break;

    case 1:

        simple_idct84_add(dst           , stride, block1);

        simple_idct84_add(dst + 4*stride, stride, w->abt_block2[n]);

        memset(w->abt_block2[n], 0, 64*sizeof(DCTELEM));

        break;

    case 2:

        simple_idct48_add(dst           , stride, block1);

        simple_idct48_add(dst + 4       , stride, w->abt_block2[n]);

        memset(w->abt_block2[n], 0, 64*sizeof(DCTELEM));

        break;

    default:

        av_log(s->avctx, AV_LOG_ERROR, "internal error in WMV2 abt\n");

    }

}
