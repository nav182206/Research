/* 
 * Paradigm            : Functional_C
 * Benchmark Sample ID : devign_4104
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=d4f7d8386693beb987382ece8bb7499955620388
 */

static int split_field_ref_list(Picture *dest, int dest_len,

                                Picture *src,  int src_len,

                                int parity,    int long_i){



    int i = split_field_half_ref_list(dest, dest_len, src, long_i, parity);

    dest += i;

    dest_len -= i;



    i += split_field_half_ref_list(dest, dest_len, src + long_i,

                                   src_len - long_i, parity);

    return i;

}
