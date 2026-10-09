/* 
 * Benchmark Sample ID : devign_7039
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=52a2c17ec006282f388071a831dfb21288611253
 */

RefPicList *ff_hevc_get_ref_list(HEVCContext *s, HEVCFrame *ref, int x0, int y0)

{

    if (x0 < 0 || y0 < 0) {

        return s->ref->refPicList;

    } else {

        int x_cb         = x0 >> s->sps->log2_ctb_size;

        int y_cb         = y0 >> s->sps->log2_ctb_size;

        int pic_width_cb = (s->sps->width + (1 << s->sps->log2_ctb_size) - 1) >>

                           s->sps->log2_ctb_size;

        int ctb_addr_ts  = s->pps->ctb_addr_rs_to_ts[y_cb * pic_width_cb + x_cb];

        return (RefPicList *)ref->rpl_tab[ctb_addr_ts];

    }

}
