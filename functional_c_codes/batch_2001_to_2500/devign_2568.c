/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_2568
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=80e103d04cf938fc1f479347d0ab2f8c6e688b61
 */

void mjpeg_picture_header(MpegEncContext *s)

{

    put_marker(&s->pb, SOI);



    jpeg_table_header(s);



    put_marker(&s->pb, SOF0);



    put_bits(&s->pb, 16, 17);

    put_bits(&s->pb, 8, 8); /* 8 bits/component */

    put_bits(&s->pb, 16, s->height);

    put_bits(&s->pb, 16, s->width);

    put_bits(&s->pb, 8, 3); /* 3 components */

    

    /* Y component */

    put_bits(&s->pb, 8, 1); /* component number */

    put_bits(&s->pb, 4, 2); /* H factor */

    put_bits(&s->pb, 4, 2); /* V factor */

    put_bits(&s->pb, 8, 0); /* select matrix */

    

    /* Cb component */

    put_bits(&s->pb, 8, 2); /* component number */

    put_bits(&s->pb, 4, 1); /* H factor */

    put_bits(&s->pb, 4, 1); /* V factor */

    put_bits(&s->pb, 8, 0); /* select matrix */



    /* Cr component */

    put_bits(&s->pb, 8, 3); /* component number */

    put_bits(&s->pb, 4, 1); /* H factor */

    put_bits(&s->pb, 4, 1); /* V factor */

    put_bits(&s->pb, 8, 0); /* select matrix */



    /* scan header */

    put_marker(&s->pb, SOS);

    put_bits(&s->pb, 16, 12); /* length */

    put_bits(&s->pb, 8, 3); /* 3 components */

    

    /* Y component */

    put_bits(&s->pb, 8, 1); /* index */

    put_bits(&s->pb, 4, 0); /* DC huffman table index */

    put_bits(&s->pb, 4, 0); /* AC huffman table index */

    

    /* Cb component */

    put_bits(&s->pb, 8, 2); /* index */

    put_bits(&s->pb, 4, 1); /* DC huffman table index */

    put_bits(&s->pb, 4, 1); /* AC huffman table index */

    

    /* Cr component */

    put_bits(&s->pb, 8, 3); /* index */

    put_bits(&s->pb, 4, 1); /* DC huffman table index */

    put_bits(&s->pb, 4, 1); /* AC huffman table index */



    put_bits(&s->pb, 8, 0); /* Ss (not used) */

    put_bits(&s->pb, 8, 63); /* Se (not used) */

    put_bits(&s->pb, 8, 0); /* (not used) */

}
