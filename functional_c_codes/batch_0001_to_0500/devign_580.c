/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_580
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=4ced5d7780fea2ea49444d6686d26f26b3a2160f
 */

void ff_hevc_set_qPy(HEVCContext *s, int xC, int yC,

                     int xBase, int yBase, int log2_cb_size)

{

    int qp_y = get_qPy_pred(s, xC, yC, xBase, yBase, log2_cb_size);



    if (s->HEVClc->tu.cu_qp_delta != 0) {

        int off = s->sps->qp_bd_offset;

        s->HEVClc->qp_y = ((qp_y + s->HEVClc->tu.cu_qp_delta + 52 + 2 * off) %

                          (52 + off)) - off;

    } else

        s->HEVClc->qp_y = qp_y;

}
