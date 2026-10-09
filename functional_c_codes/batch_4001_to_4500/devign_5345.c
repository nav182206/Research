/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_5345
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=28eddef689f2b4843a84f7d05fd9614246f92cc4
 */

static int hq_decode_block(HQContext *c, GetBitContext *gb, int16_t block[64],

                           int qsel, int is_chroma, int is_hqa)

{

    const int32_t *q;

    int val, pos = 1;



    memset(block, 0, 64 * sizeof(*block));



    if (!is_hqa) {

        block[0] = get_sbits(gb, 9) << 6;

        q = ff_hq_quants[qsel][is_chroma][get_bits(gb, 2)];

    } else {

        q = ff_hq_quants[qsel][is_chroma][get_bits(gb, 2)];

        block[0] = get_sbits(gb, 9) << 6;

    }



    for (;;) {

        val  = get_vlc2(gb, c->hq_ac_vlc.table, 9, 2);

        pos += ff_hq_ac_skips[val];

        if (pos >= 64)

            break;

        block[ff_zigzag_direct[pos]] = (ff_hq_ac_syms[val] * q[pos]) >> 12;

        pos++;

    }



    return 0;

}
