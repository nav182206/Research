/* 
 * Benchmark Sample ID : devign_2188
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=f1e173049ecc9de03817385ba8962d14cba779db
 */

static void dequantization_int_97(int x, int y, Jpeg2000Cblk *cblk,

                               Jpeg2000Component *comp,

                               Jpeg2000T1Context *t1, Jpeg2000Band *band)

{

    int i, j;

    int w = cblk->coord[0][1] - cblk->coord[0][0];

    for (j = 0; j < (cblk->coord[1][1] - cblk->coord[1][0]); ++j) {

        int32_t *datap = &comp->i_data[(comp->coord[0][1] - comp->coord[0][0]) * (y + j) + x];

        int *src = t1->data[j];

        for (i = 0; i < w; ++i)

            datap[i] = (src[i] * (int64_t)band->i_stepsize + (1<<14)) >> 15;

    }

}
