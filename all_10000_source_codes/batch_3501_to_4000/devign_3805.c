/* 
 * Benchmark Sample ID : devign_3805
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3faa303a47e0c3b59a53988e0f76018930c6cb1a
 */

static inline void rv34_decode_block(DCTELEM *dst, GetBitContext *gb, RV34VLC *rvlc, int fc, int sc, int q_dc, int q_ac1, int q_ac2)

{

    int code, pattern;



    code = get_vlc2(gb, rvlc->first_pattern[fc].table, 9, 2);



    pattern = code & 0x7;



    code >>= 3;

    decode_subblock3(dst, code, 0, gb, &rvlc->coefficient, q_dc, q_ac1, q_ac2);



    if(pattern & 4){

        code = get_vlc2(gb, rvlc->second_pattern[sc].table, 9, 2);

        decode_subblock(dst + 2, code, 0, gb, &rvlc->coefficient, q_ac2);

    }

    if(pattern & 2){ // Looks like coefficients 1 and 2 are swapped for this block

        code = get_vlc2(gb, rvlc->second_pattern[sc].table, 9, 2);

        decode_subblock(dst + 8*2, code, 1, gb, &rvlc->coefficient, q_ac2);

    }

    if(pattern & 1){

        code = get_vlc2(gb, rvlc->third_pattern[sc].table, 9, 2);

        decode_subblock(dst + 8*2+2, code, 0, gb, &rvlc->coefficient, q_ac2);

    }



}
