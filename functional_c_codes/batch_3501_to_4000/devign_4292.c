/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4292
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=073c2593c9f0aa4445a6fc1b9b24e6e52a8cc2c1
 */

static void init_vlcs(void)

{

    static int done = 0;



    if (!done) {

        done = 1;



        init_vlc(&dc_lum_vlc, DC_VLC_BITS, 12, 

                 vlc_dc_lum_bits, 1, 1,

                 vlc_dc_lum_code, 2, 2);

        init_vlc(&dc_chroma_vlc,  DC_VLC_BITS, 12, 

                 vlc_dc_chroma_bits, 1, 1,

                 vlc_dc_chroma_code, 2, 2);

        init_vlc(&mv_vlc, MV_VLC_BITS, 17, 

                 &mbMotionVectorTable[0][1], 2, 1,

                 &mbMotionVectorTable[0][0], 2, 1);

        init_vlc(&mbincr_vlc, MBINCR_VLC_BITS, 36, 

                 &mbAddrIncrTable[0][1], 2, 1,

                 &mbAddrIncrTable[0][0], 2, 1);

        init_vlc(&mb_pat_vlc, MB_PAT_VLC_BITS, 64,

                 &mbPatTable[0][1], 2, 1,

                 &mbPatTable[0][0], 2, 1);

        

        init_vlc(&mb_ptype_vlc, MB_PTYPE_VLC_BITS, 7, 

                 &table_mb_ptype[0][1], 2, 1,

                 &table_mb_ptype[0][0], 2, 1);

        init_vlc(&mb_btype_vlc, MB_BTYPE_VLC_BITS, 11, 

                 &table_mb_btype[0][1], 2, 1,

                 &table_mb_btype[0][0], 2, 1);

        init_rl(&rl_mpeg1);

        init_rl(&rl_mpeg2);



        init_2d_vlc_rl(&rl_mpeg1);

        init_2d_vlc_rl(&rl_mpeg2);

    }

}
