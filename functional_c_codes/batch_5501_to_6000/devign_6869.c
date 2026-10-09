/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_6869
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d7eabd50425a61b31e90c763a0c3e4316a725404
 */

static int get_scale_idx(GetBitContext *gb, int ref)

{

    int t = get_vlc2(gb, dscf_vlc.table, MPC7_DSCF_BITS, 1) - 7;

    if (t == 8)

        return get_bits(gb, 6);

    return ref + t;

}
