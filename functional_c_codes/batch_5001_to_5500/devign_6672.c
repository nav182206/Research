/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6672
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=ca41c72c6d9515d9045bd3b68104525dee81b8d0
 */

static int mp_get_vlc(MotionPixelsContext *mp, GetBitContext *gb)

{

    int i;



    i = (mp->codes_count == 1) ? 0 : get_vlc2(gb, mp->vlc.table, mp->max_codes_bits, 1);


    return mp->codes[i].delta;

}
