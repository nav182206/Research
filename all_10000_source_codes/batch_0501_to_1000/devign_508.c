/* 
 * Benchmark Sample ID : devign_508
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=90f03441654f85a1402a65c3dcaa3f634a24c27e
 */

static uint32_t calc_optimal_rice_params(RiceContext *rc, int porder,

                                         uint32_t *sums, int n, int pred_order)

{

    int i;

    int k, cnt, part;

    uint32_t all_bits;



    part = (1 << porder);

    all_bits = 0;



    cnt = (n >> porder) - pred_order;

    for(i=0; i<part; i++) {

        if(i == 1) cnt = (n >> porder);

        k = find_optimal_param(sums[i], cnt);

        rc->params[i] = k;

        all_bits += rice_encode_count(sums[i], cnt, k);

    }

    all_bits += (4 * part);



    rc->porder = porder;



    return all_bits;

}
