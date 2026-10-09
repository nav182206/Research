/* 
 * Benchmark Sample ID : devign_5146
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=465c28b6b43be2563e0b644ec22cf641fe374d8d
 */

static int matroska_ebmlnum_uint(MatroskaDemuxContext *matroska,

                                 uint8_t *data, uint32_t size, uint64_t *num)

{

    ByteIOContext pb;

    init_put_byte(&pb, data, size, 0, NULL, NULL, NULL, NULL);

    return ebml_read_num(matroska, &pb, 8, num);

}
