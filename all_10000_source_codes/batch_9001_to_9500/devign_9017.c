/* 
 * Benchmark Sample ID : devign_9017
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=9ea242962c4093a5523deef124a98193bbb36730
 */

Jpeg2000TgtNode *ff_j2k_tag_tree_init(int w, int h)

{

    int pw = w, ph = h;

    Jpeg2000TgtNode *res, *t, *t2;

    int32_t tt_size;



    tt_size = tag_tree_size(w, h);



    t = res = av_mallocz(tt_size, sizeof(*t));

    if (!res)

        return NULL;



    while (w > 1 || h > 1) {

        int i, j;

        pw = w;

        ph = h;



        w  = (w + 1) >> 1;

        h  = (h + 1) >> 1;

        t2 = t + pw * ph;



        for (i = 0; i < ph; i++)

            for (j = 0; j < pw; j++)

                t[i * pw + j].parent = &t2[(i >> 1) * w + (j >> 1)];



        t = t2;

    }

    t[0].parent = NULL;

    return res;

}
