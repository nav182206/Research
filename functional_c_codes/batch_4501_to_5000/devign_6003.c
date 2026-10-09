/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6003
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=bcd7bf7eeb09a395cc01698842d1b8be9af483fc
 */

void ff_h264_v_lpf_luma_inter_msa(uint8_t *data, int img_width,

                                  int alpha, int beta, int8_t *tc)

{



    uint8_t bs0 = 1;

    uint8_t bs1 = 1;

    uint8_t bs2 = 1;

    uint8_t bs3 = 1;



    if (tc[0] < 0)

        bs0 = 0;

    if (tc[1] < 0)

        bs1 = 0;

    if (tc[2] < 0)

        bs2 = 0;

    if (tc[3] < 0)

        bs3 = 0;



    avc_loopfilter_luma_inter_edge_hor_msa(data,

                                           bs0, bs1, bs2, bs3,

                                           tc[0], tc[1], tc[2], tc[3],

                                           alpha, beta, img_width);

}
