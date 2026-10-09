/* 
 * Benchmark Sample ID : devign_8882
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=933aa91e31d5cbf9dbc0cf416a988e6011bc4a40
 */

static void cabac_init_decoder(HEVCContext *s)

{

    GetBitContext *gb = &s->HEVClc->gb;

    skip_bits(gb, 1);

    align_get_bits(gb);

    ff_init_cabac_decoder(&s->HEVClc->cc,

                          gb->buffer + get_bits_count(gb) / 8,

                          (get_bits_left(gb) + 7) / 8);

}
