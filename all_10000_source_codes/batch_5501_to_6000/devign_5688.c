/* 
 * Benchmark Sample ID : devign_5688
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=473147bed01c0c6c82d85fd79d3e1c1d65542663
 */

static void decodeplane32(uint32_t *dst, const uint8_t *const buf, int buf_size, int bps, int plane)

{

    GetBitContext gb;

    int i, b;

    init_get_bits(&gb, buf, buf_size * 8);

    for(i = 0; i < (buf_size * 8 + bps - 1) / bps; i++) {

        for (b = 0; b < bps; b++) {

            dst[ i*bps + b ] |= get_bits1(&gb) << plane;

        }

    }

}
