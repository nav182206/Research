/* 
 * Benchmark Sample ID : devign_4625
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=8d637124864dcf8bf367ab96e572d6c7cf043675
 */

static void skip_data_stream_element(GetBitContext *gb)

{

    int byte_align = get_bits1(gb);

    int count = get_bits(gb, 8);

    if (count == 255)

        count += get_bits(gb, 8);

    if (byte_align)

        align_get_bits(gb);

    skip_bits_long(gb, 8 * count);

}
