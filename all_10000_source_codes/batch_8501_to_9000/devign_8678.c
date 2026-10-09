/* 
 * Benchmark Sample ID : devign_8678
 * Dataset Source      : Devign
 * Project Origin      : FFmpeg
 * Vulnerability CWE   : CWE-MemorySafety
 * Paradigm            : Functional_C
 * Ground Truth Label  : CLEAN (0)
 * GitHub Patch Trace  : https://github.com/search?q=403ee835e7913eb9536b22c2b22edfdd700166a9
 */

int url_open_dyn_packet_buf(AVIOContext **s, int max_packet_size)

{

    if (max_packet_size <= 0)

        return -1;

    return url_open_dyn_buf_internal(s, max_packet_size);

}
