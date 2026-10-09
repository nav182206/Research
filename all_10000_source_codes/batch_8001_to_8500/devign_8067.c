/* 
 * Benchmark Sample ID : devign_8067
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=3deb4b54a24f8cddce463d9f5751b01efeb976af
 */

static int parse_packet_header(WMAVoiceContext *s)

{

    GetBitContext *gb = &s->gb;

    unsigned int res;



    if (get_bits_left(gb) < 11)

        return 1;

    skip_bits(gb, 4);          // packet sequence number

    s->has_residual_lsps = get_bits1(gb);

    do {

        res = get_bits(gb, 6); // number of superframes per packet

                               // (minus first one if there is spillover)

        if (get_bits_left(gb) < 6 * (res == 0x3F) + s->spillover_bitsize)

            return 1;

    } while (res == 0x3F);

    s->spillover_nbits   = get_bits(gb, s->spillover_bitsize);



    return 0;

}
