/* 
 * Benchmark Sample ID : devign_1783
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3176217c60ca7828712985092d9102d331ea4f3d
 */

void ff_h264_init_cabac_states(const H264Context *h, H264SliceContext *sl)

{

    int i;

    const int8_t (*tab)[2];

    const int slice_qp = av_clip(sl->qscale - 6*(h->sps.bit_depth_luma-8), 0, 51);



    if (sl->slice_type_nos == AV_PICTURE_TYPE_I) tab = cabac_context_init_I;

    else                                 tab = cabac_context_init_PB[sl->cabac_init_idc];



    /* calculate pre-state */

    for( i= 0; i < 1024; i++ ) {

        int pre = 2*(((tab[i][0] * slice_qp) >>4 ) + tab[i][1]) - 127;



        pre^= pre>>31;

        if(pre > 124)

            pre= 124 + (pre&1);



        sl->cabac_state[i] =  pre;

    }

}
