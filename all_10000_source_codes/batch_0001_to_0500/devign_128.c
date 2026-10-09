/* 
 * Benchmark Sample ID : devign_128
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : VULNERABLE (1)
 * GitHub Patch Trace  : https://github.com/search?q=babf4fe01a808327d53977ba319c113a930180b1
 */

static void idr(H264Context *h){

    int i;

    ff_h264_remove_all_refs(h);

    h->prev_frame_num= 0;

    h->prev_frame_num_offset= 0;

    h->prev_poc_msb=

    h->prev_poc_lsb= 0;

    for (i = 0; i < MAX_DELAYED_PIC_COUNT; i++)

        h->last_pocs[i] = INT_MIN;

}
