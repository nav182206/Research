/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_7989
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d23b28c78b56f53f3f0e74edb0f15a3b451207ad
 */

static inline void decode_hrd_parameters(H264Context *h, SPS *sps){

    MpegEncContext * const s = &h->s;

    int cpb_count, i;

    cpb_count = get_ue_golomb(&s->gb) + 1;

    get_bits(&s->gb, 4); /* bit_rate_scale */

    get_bits(&s->gb, 4); /* cpb_size_scale */

    for(i=0; i<cpb_count; i++){

        get_ue_golomb(&s->gb); /* bit_rate_value_minus1 */

        get_ue_golomb(&s->gb); /* cpb_size_value_minus1 */

        get_bits1(&s->gb);     /* cbr_flag */

    }

    get_bits(&s->gb, 5); /* initial_cpb_removal_delay_length_minus1 */

    sps->cpb_removal_delay_length = get_bits(&s->gb, 5) + 1;

    sps->dpb_output_delay_length = get_bits(&s->gb, 5) + 1;

    sps->time_offset_length = get_bits(&s->gb, 5);

}
