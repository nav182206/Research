/* 
 * Benchmark Sample ID : devign_1641
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=d7e9533aa06f4073a27812349b35ba5fede11ca1
 */

static void mpeg_decode_quant_matrix_extension(MpegEncContext *s)

{

    int i, v, j;



    dprintf("matrix extension\n");



    if (get_bits1(&s->gb)) {

        for(i=0;i<64;i++) {

            v = get_bits(&s->gb, 8);

            j = zigzag_direct[i];

            s->intra_matrix[j] = v;

            s->chroma_intra_matrix[j] = v;

        }

    }

    if (get_bits1(&s->gb)) {

        for(i=0;i<64;i++) {

            v = get_bits(&s->gb, 8);

            j = zigzag_direct[i];

            s->non_intra_matrix[j] = v;

            s->chroma_non_intra_matrix[j] = v;

        }

    }

    if (get_bits1(&s->gb)) {

        for(i=0;i<64;i++) {

            v = get_bits(&s->gb, 8);

            j = zigzag_direct[i];

            s->chroma_intra_matrix[j] = v;

        }

    }

    if (get_bits1(&s->gb)) {

        for(i=0;i<64;i++) {

            v = get_bits(&s->gb, 8);

            j = zigzag_direct[i];

            s->chroma_non_intra_matrix[j] = v;

        }

    }

}
