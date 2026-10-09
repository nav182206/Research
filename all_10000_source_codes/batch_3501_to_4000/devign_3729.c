/* 
 * Benchmark Sample ID : devign_3729
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=e91ba2efa949470e9157b652535d207a101f91e0
 */

static void svq1_parse_string(GetBitContext *bitbuf, uint8_t *out)

{

    uint8_t seed;

    int i;



    out[0] = get_bits(bitbuf, 8);

    seed   = string_table[out[0]];



    for (i = 1; i <= out[0]; i++) {

        out[i] = get_bits(bitbuf, 8) ^ seed;

        seed   = string_table[out[i] ^ seed];

    }

}
