/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_3467
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=0d0d24af0159ff08f396ad04cd63ce5655b1fc60
 */

static void parse_ptl(HEVCContext *s, PTL *ptl, int max_num_sub_layers)

{

    int i;

    HEVCLocalContext *lc = s->HEVClc;

    GetBitContext *gb = &lc->gb;

    decode_profile_tier_level(s, &ptl->general_ptl);

    ptl->general_ptl.level_idc = get_bits(gb, 8);



    for (i = 0; i < max_num_sub_layers - 1; i++) {

        ptl->sub_layer_profile_present_flag[i] = get_bits1(gb);

        ptl->sub_layer_level_present_flag[i]   = get_bits1(gb);

    }

    if (max_num_sub_layers - 1> 0)

        for (i = max_num_sub_layers - 1; i < 8; i++)

            skip_bits(gb, 2); // reserved_zero_2bits[i]

    for (i = 0; i < max_num_sub_layers - 1; i++) {

        if (ptl->sub_layer_profile_present_flag[i])

            decode_profile_tier_level(s, &ptl->sub_layer_ptl[i]);

        if (ptl->sub_layer_level_present_flag[i])

            ptl->sub_layer_ptl[i].level_idc = get_bits(gb, 8);

    }

}
