/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2311
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c619ff6daf93a8f3c03decf2d3345d2474c3db91
 */

static inline void bit_copy(PutBitContext *pb, GetBitContext *gb)

{

    int bits_left = get_bits_left(gb);

    while (bits_left >= 16) {

        put_bits(pb, 16, get_bits(gb, 16));

        bits_left -= 16;

    }

    if (bits_left > 0) {

        put_bits(pb, bits_left, get_bits(gb, bits_left));

    }

}
