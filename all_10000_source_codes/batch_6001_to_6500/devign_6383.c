/* 
 * Benchmark Sample ID : devign_6383
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=a6191d098a03f94685ae4c072bfdf10afcd86223
 */

static void shift_history(DCAEncContext *c, const int32_t *input)

{

    int k, ch;



    for (k = 0; k < 512; k++)

        for (ch = 0; ch < c->channels; ch++) {

            const int chi = c->channel_order_tab[ch];



            c->history[k][ch] = input[k * c->channels + chi];

        }

}
