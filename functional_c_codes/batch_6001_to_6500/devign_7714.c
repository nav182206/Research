/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7714
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=851ded8918c977d8160c6617b69604f758cabf50
 */

static int decode_cabac_field_decoding_flag(H264Context *h) {

    MpegEncContext * const s = &h->s;

    const int mb_x = s->mb_x;

    const int mb_y = s->mb_y & ~1;

    const int mba_xy = mb_x - 1 +  mb_y   *s->mb_stride;

    const int mbb_xy = mb_x     + (mb_y-2)*s->mb_stride;



    unsigned int ctx = 0;



    if( h->slice_table[mba_xy] == h->slice_num && IS_INTERLACED( s->current_picture.mb_type[mba_xy] ) ) {

        ctx += 1;

    }

    if( h->slice_table[mbb_xy] == h->slice_num && IS_INTERLACED( s->current_picture.mb_type[mbb_xy] ) ) {

        ctx += 1;

    }



    return get_cabac( &h->cabac, &h->cabac_state[70 + ctx] );

}
