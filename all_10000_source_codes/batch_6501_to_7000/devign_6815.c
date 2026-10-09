/* 
 * Benchmark Sample ID : devign_6815
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=dcf5bfbdb6137ffdca66e0b7c2929ced42732951
 */

static int read_bfraction(VC1Context *v, GetBitContext* gb) {

    v->bfraction_lut_index = get_vlc2(gb, ff_vc1_bfraction_vlc.table, VC1_BFRACTION_VLC_BITS, 1);

    v->bfraction           = ff_vc1_bfraction_lut[v->bfraction_lut_index];

    return 0;

}
