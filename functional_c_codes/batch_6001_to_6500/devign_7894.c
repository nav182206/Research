/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7894
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=7cc84d241ba6ef8e27e4d057176a4ad385ad3d59
 */

static int advanced_decode_picture_secondary_header(VC9Context *v)

{

    GetBitContext *gb = &v->s.gb;

    int index, status = 0;



    switch(v->s.pict_type)

    {

    case P_TYPE: status = decode_p_picture_secondary_header(v); break;

    case B_TYPE: status = decode_b_picture_secondary_header(v); break;

    case BI_TYPE:

    case I_TYPE: status = decode_i_picture_secondary_header(v); break; 

    }

    if (status<0) return FRAME_SKIPED;



    /* AC Syntax */

    v->ac_table_level = decode012(gb);

    if (v->s.pict_type == I_TYPE || v->s.pict_type == BI_TYPE)

    {

        v->ac2_table_level = decode012(gb);

    }

    /* DC Syntax */

    index = decode012(gb);

    v->luma_dc_vlc = &ff_msmp4_dc_luma_vlc[index];

    v->chroma_dc_vlc = &ff_msmp4_dc_chroma_vlc[index];



    return 0;

}
