/* 
 * Benchmark Sample ID : devign_822
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0b247953c8c63baba1da93e555baff177cdf2137
 */

static void put_ebml_uint(ByteIOContext *pb, unsigned int elementid, uint64_t val)

{

    int i, bytes = 1;

    while (val >> bytes*8 && bytes < 8) bytes++;



    put_ebml_id(pb, elementid);

    put_ebml_num(pb, bytes, 0);

    for (i = bytes - 1; i >= 0; i--)

        put_byte(pb, val >> i*8);

}
