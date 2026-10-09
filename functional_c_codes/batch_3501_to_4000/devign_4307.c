/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4307
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=f4a8a0080537484154bb74e08ec76cbcbd25484b
 */

static int read_rle_sgi(uint8_t *out_buf, SgiState *s)

{

    uint8_t *dest_row;

    unsigned int len = s->height * s->depth * 4;

    GetByteContext g_table = s->g;

    unsigned int y, z;

    unsigned int start_offset;



    /* size of  RLE offset and length tables */

    if (len * 2  > bytestream2_get_bytes_left(&s->g)) {

        return AVERROR_INVALIDDATA;

    }



    for (z = 0; z < s->depth; z++) {

        dest_row = out_buf;

        for (y = 0; y < s->height; y++) {

            dest_row -= s->linesize;

            start_offset = bytestream2_get_be32(&g_table);

            bytestream2_seek(&s->g, start_offset, SEEK_SET);

            if (expand_rle_row(s, dest_row + z, dest_row + FFABS(s->linesize),

                               s->depth) != s->width) {

                return AVERROR_INVALIDDATA;

            }

        }

    }

    return 0;

}
