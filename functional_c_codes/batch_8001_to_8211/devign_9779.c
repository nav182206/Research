/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_9779
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=c51c08e0e70c186971385bdbb225f69edd4e3375
 */

static int decode_display_orientation(H264Context *h)

{

    h->sei_display_orientation_present = !get_bits1(&h->gb);



    if (h->sei_display_orientation_present) {

        h->sei_hflip = get_bits1(&h->gb);     // hor_flip

        h->sei_vflip = get_bits1(&h->gb);     // ver_flip



        h->sei_anticlockwise_rotation = get_bits(&h->gb, 16);

        get_ue_golomb(&h->gb);  // display_orientation_repetition_period

        skip_bits1(&h->gb);     // display_orientation_extension_flag

    }



    return 0;

}
