/* 
 * Benchmark Sample ID : devign_17
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=323e6fead07c75f418e4b60704a4f437bb3483b2
 */

static void quantize_mantissas(AC3EncodeContext *s)

{

    int blk, ch;





    for (blk = 0; blk < AC3_MAX_BLOCKS; blk++) {

        AC3Block *block = &s->blocks[blk];

        s->mant1_cnt  = s->mant2_cnt  = s->mant4_cnt  = 0;

        s->qmant1_ptr = s->qmant2_ptr = s->qmant4_ptr = NULL;



        for (ch = 0; ch < s->channels; ch++) {

            quantize_mantissas_blk_ch(s, block->fixed_coef[ch], block->exp_shift[ch],

                                      block->exp[ch], block->bap[ch],

                                      block->qmant[ch], s->nb_coefs[ch]);

        }

    }

}
